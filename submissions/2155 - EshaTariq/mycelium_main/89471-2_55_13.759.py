def solve(xg, yg, xm, ym):
	"""
	Calculate total number of tiles mycelium will ever occupy.
	
	Grass spreads at ticks 2, 4, 6, ... (every 2 ticks)
	Mycelium spreads at ticks 7, 14, 21, ... (every 7 ticks)
	If both convert same tile on same tick, it becomes grass.
	
	xg, yg: Initial grass position
	xm, ym: Initial mycelium position
	"""
	
	# Use BFS/simulation to find all mycelium tiles
	grass = {(xg, yg)}
	mycelium = {(xm, ym)}
	
	# Simulate enough ticks to reach equilibrium
	# Key insight: after enough ticks, pattern stabilizes
	max_ticks = 10000
	
	for tick in range(1, max_ticks + 1):
		new_grass = set(grass)
		new_mycelium = set(mycelium)
		
		# Grass spreads every 2 ticks
		if tick % 2 == 0:
			temp_grass = set(grass)
			for x, y in grass:
				for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
					nx, ny = x + dx, y + dy
					if (nx, ny) not in grass and (nx, ny) not in mycelium:
						temp_grass.add((nx, ny))
			new_grass = temp_grass
		
		# Mycelium spreads every 7 ticks
		if tick % 7 == 0:
			temp_mycelium = set(mycelium)
			for x, y in mycelium:
				for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
					nx, ny = x + dx, y + dy
					if (nx, ny) not in grass and (nx, ny) not in mycelium:
						temp_mycelium.add((nx, ny))
					elif (nx, ny) in grass:
						# Both spread to same tile, grass wins
						temp_mycelium.discard((nx, ny))
			new_mycelium = temp_mycelium
		
		# Handle simultaneous conversion on same tick
		if tick % 2 == 0 and tick % 7 == 0:
			# Both spread, grass wins on conflicts
			new_grass |= (new_mycelium & new_grass)
			new_mycelium -= new_grass
		
		# Check if stabilized
		if new_grass == grass and new_mycelium == mycelium:
			return len(mycelium)
		
		grass = new_grass
		mycelium = new_mycelium
	
	return len(mycelium)

def main():
	T = int(input())
	for _ in range(T):
		temp = input().split()
		xg = int(temp[0])
		yg = int(temp[1])
		xm = int(temp[2])
		ym = int(temp[3])
		
		result = solve(xg, yg, xm, ym)
		print(result)

if __name__ == "__main__":
	main()