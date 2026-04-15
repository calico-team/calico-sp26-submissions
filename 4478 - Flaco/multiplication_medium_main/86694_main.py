import heapq
import math
import sys
from array import array


def solve(
    n_variables,
    n_equations,
    drop_limit,
    equation_left,
    equation_right,
    equation_value,
    equation_weight,
    log_equation_value,
):
    min_label = 1
    max_label = 1_000_000_000
    max_log_label = math.log(max_label)

    all_edge_indices = range(n_equations)

    # Solve in log-space so products become sums and stay numerically stable.
    def run_relaxation(rounds, label_logs, edge_indices, step=0.7):
        left = equation_left
        right = equation_right
        weight_arr = equation_weight
        log_target_arr = log_equation_value
        var_count = n_variables

        for _ in range(rounds):
            weighted_targets = [0.0] * var_count
            total_weight = [0.0] * var_count

            for eq_idx in edge_indices:
                lhs = left[eq_idx]
                rhs = right[eq_idx]
                weight = weight_arr[eq_idx]
                log_target = log_target_arr[eq_idx]

                weighted_targets[lhs] += weight * (log_target - label_logs[rhs])
                total_weight[lhs] += weight
                weighted_targets[rhs] += weight * (log_target - label_logs[lhs])
                total_weight[rhs] += weight

            for var_id in range(var_count):
                if total_weight[var_id] == 0.0:
                    continue

                target = weighted_targets[var_id] / total_weight[var_id]
                updated = label_logs[var_id] + step * (target - label_logs[var_id])

                if updated < 0.0:
                    updated = 0.0
                elif updated > max_log_label:
                    updated = max_log_label

                label_logs[var_id] = updated

        return label_logs

    def dropped_ids_to_kept_indices(dropped_ids):
        mask = bytearray(n_equations)
        for eq_id in dropped_ids:
            mask[eq_id - 1] = 1
        return [idx for idx in all_edge_indices if not mask[idx]]

    def discretize_labels(label_logs):
        labels = [1] * n_variables
        for var_id in range(n_variables):
            raw = int(round(math.exp(label_logs[var_id])))
            if raw < min_label:
                raw = min_label
            elif raw > max_label:
                raw = max_label
            labels[var_id] = raw
        return labels

    def pick_noisiest_log_equations(current_logs):
        worst_heap = []
        heappush = heapq.heappush
        heapreplace = heapq.heapreplace

        for eq_idx in range(n_equations):
            lhs = equation_left[eq_idx]
            rhs = equation_right[eq_idx]
            weight = equation_weight[eq_idx]

            log_error = abs(current_logs[lhs] + current_logs[rhs] - log_equation_value[eq_idx])
            score = weight * log_error

            if len(worst_heap) < drop_limit:
                heappush(worst_heap, (score, eq_idx + 1))
            elif score > worst_heap[0][0]:
                heapreplace(worst_heap, (score, eq_idx + 1))

        return [eq_id for _, eq_id in worst_heap]

    def pick_noisiest_equations(current_labels):
        worst_heap = []
        heappush = heapq.heappush
        heapreplace = heapq.heapreplace

        for eq_idx in range(n_equations):
            lhs = equation_left[eq_idx]
            rhs = equation_right[eq_idx]
            target_product = equation_value[eq_idx]
            weight = equation_weight[eq_idx]

            predicted_product = current_labels[lhs] * current_labels[rhs]
            score = weight * abs(predicted_product - target_product) / target_product

            if len(worst_heap) < drop_limit:
                heappush(worst_heap, (score, eq_idx + 1))
            elif score > worst_heap[0][0]:
                heapreplace(worst_heap, (score, eq_idx + 1))

        return [eq_id for _, eq_id in worst_heap]

    def evaluate_labels(current_labels):
        if drop_limit <= 0:
            total_penalty = 0.0
            for eq_idx in all_edge_indices:
                lhs = equation_left[eq_idx]
                rhs = equation_right[eq_idx]
                target_product = equation_value[eq_idx]
                weight = equation_weight[eq_idx]
                predicted_product = current_labels[lhs] * current_labels[rhs]
                total_penalty += weight * abs(predicted_product - target_product) / target_product
            return total_penalty, []

        if drop_limit >= n_equations:
            return 0.0, list(range(1, n_equations + 1))

        worst_heap = []
        heappush = heapq.heappush
        heapreplace = heapq.heapreplace
        total_penalty = 0.0

        for eq_idx in all_edge_indices:
            lhs = equation_left[eq_idx]
            rhs = equation_right[eq_idx]
            target_product = equation_value[eq_idx]
            weight = equation_weight[eq_idx]

            predicted_product = current_labels[lhs] * current_labels[rhs]
            score = weight * abs(predicted_product - target_product) / target_product
            total_penalty += score

            if len(worst_heap) < drop_limit:
                heappush(worst_heap, (score, eq_idx + 1))
            elif score > worst_heap[0][0]:
                heapreplace(worst_heap, (score, eq_idx + 1))

        removed_penalty = 0.0
        for score, _ in worst_heap:
            removed_penalty += score
        dropped_ids = [eq_id for _, eq_id in worst_heap]
        return total_penalty - removed_penalty, dropped_ids

    def fit_once(initial_logs):
        label_logs = initial_logs[:]
        label_logs = run_relaxation(rounds=4, label_logs=label_logs, edge_indices=all_edge_indices)
        labels = discretize_labels(label_logs)

        dropped_for_refit = pick_noisiest_log_equations(label_logs)
        if dropped_for_refit:
            max_refits = 2 if n_equations <= 400_000 else 1

            for refit_round in range(max_refits):
                kept_edge_indices = dropped_ids_to_kept_indices(dropped_for_refit)
                if refit_round == 0:
                    if n_equations <= 200_000:
                        rounds = 6
                    elif n_equations <= 400_000:
                        rounds = 10
                    else:
                        rounds = 5
                else:
                    rounds = 2

                label_logs = run_relaxation(
                    rounds=rounds,
                    label_logs=label_logs,
                    edge_indices=kept_edge_indices,
                    step=0.7,
                )

                if refit_round + 1 < max_refits:
                    next_dropped = pick_noisiest_log_equations(label_logs)
                    if next_dropped == dropped_for_refit:
                        break
                    dropped_for_refit = next_dropped

            labels = discretize_labels(label_logs)

        penalty, dropped_equations = evaluate_labels(labels)
        return penalty, labels, dropped_equations

    def weighted_median_refinement(start_labels, sweeps=2):
        adjacency = [[] for _ in range(n_variables)]
        for eq_idx in all_edge_indices:
            adjacency[equation_left[eq_idx]].append(eq_idx)
            adjacency[equation_right[eq_idx]].append(eq_idx)

        current_labels = start_labels[:]
        current_penalty, current_dropped = evaluate_labels(current_labels)

        for _ in range(sweeps):
            dropped_mask = bytearray(n_equations)
            for eq_id in current_dropped:
                dropped_mask[eq_id - 1] = 1

            for node_id in range(n_variables):
                median_candidates = []

                for eq_idx in adjacency[node_id]:
                    if dropped_mask[eq_idx]:
                        continue

                    if equation_left[eq_idx] == node_id:
                        other_value = current_labels[equation_right[eq_idx]]
                    else:
                        other_value = current_labels[equation_left[eq_idx]]

                    target = equation_value[eq_idx] / other_value
                    weight = (equation_weight[eq_idx] * other_value) / equation_value[eq_idx]
                    median_candidates.append((target, weight))

                if not median_candidates:
                    continue

                median_candidates.sort(key=lambda pair: pair[0])
                half_weight = 0.5 * sum(weight for _, weight in median_candidates)

                acc_weight = 0.0
                selected_target = median_candidates[-1][0]
                for target, weight in median_candidates:
                    acc_weight += weight
                    if acc_weight >= half_weight:
                        selected_target = target
                        break

                candidate_value = int(round(selected_target))
                if candidate_value < min_label:
                    candidate_value = min_label
                elif candidate_value > max_label:
                    candidate_value = max_label

                current_labels[node_id] = candidate_value

            current_penalty, current_dropped = evaluate_labels(current_labels)

        return current_penalty, current_labels, current_dropped

    _, best_labels, best_dropped = fit_once([0.0] * n_variables)

    if n_equations <= 400_000 and drop_limit > 0:
        refined_penalty, refined_labels, refined_dropped = weighted_median_refinement(
            best_labels,
            sweeps=2,
        )

        base_penalty, _ = evaluate_labels(best_labels)
        if refined_penalty < base_penalty:
            return refined_labels, refined_dropped

    return best_labels, best_dropped


def ints_from_stdin():
    # Byte parser is faster than split() for large contest inputs.
    data = sys.stdin.buffer.read()
    num = 0
    sign = 1
    in_num = False
    for b in data:
        if 48 <= b <= 57:
            num = num * 10 + (b - 48)
            in_num = True
        elif b == 45:
            sign = -1
        else:
            if in_num:
                yield sign * num
                num = 0
                sign = 1
                in_num = False
    if in_num:
        yield sign * num


def main():
    it = iter(ints_from_stdin())
    try:
        n_variables = next(it)
    except StopIteration:
        return
    n_equations = next(it)
    drop_limit = next(it)

    equation_left = array("I")
    equation_right = array("I")
    equation_value = array("I")
    equation_weight = array("I")
    log_equation_value = array("d")

    for _ in range(n_equations):
        lhs = next(it) - 1
        rhs = next(it) - 1
        product_value = next(it)
        weight = next(it)
        equation_left.append(lhs)
        equation_right.append(rhs)
        equation_value.append(product_value)
        equation_weight.append(weight)
        log_equation_value.append(math.log(product_value))

    labels, dropped_equations = solve(
        n_variables,
        n_equations,
        drop_limit,
        equation_left,
        equation_right,
        equation_value,
        equation_weight,
        log_equation_value,
    )

    sys.stdout.write(" ".join(str(value) for value in labels) + "\n")
    if dropped_equations:
        output = [len(dropped_equations)] + dropped_equations
        sys.stdout.write(" ".join(str(value) for value in output) + "\n")
    else:
        sys.stdout.write("0\n")


if __name__ == "__main__":
    main()
