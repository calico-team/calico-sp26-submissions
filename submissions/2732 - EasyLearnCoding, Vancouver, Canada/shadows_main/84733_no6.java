import java.io.*;
import java.util.*;


public class no6 {

    public static void main(String[] args) {
        try {
            AnalysisCore core = new AnalysisCore(System.in, System.out);
            core.initialize();
        } catch (Exception ignored) {

        }
    }
}

class AnalysisCore {
    private final FastDataPipeline pipeline;
    private final PrintWriter reporter;

    public AnalysisCore(InputStream in, OutputStream out) {
        this.pipeline = new FastDataPipeline(in);
        this.reporter = new PrintWriter(out);
    }

    public void initialize() throws IOException {
        int batchSize = pipeline.readInt();
        while (batchSize-- > 0) {
            processSignalCycle();
        }
        reporter.flush();
    }

    private void processSignalCycle() throws IOException {
        int dimensions = pipeline.readInt();

        long[] primarySpectra = captureSpectralState(dimensions);
        long[] auxiliarySpectra = captureSpectralState(dimensions);

        IntegratedMetrics metrics = computeInteractionMetrics(primarySpectra, auxiliarySpectra);

        reporter.println(metrics.getUpperIntegrity() + " " + metrics.getLowerThreshold());
    }

    private long[] captureSpectralState(int n) throws IOException {
        long[] profile = new long[n];
        for (int i = 0; i < n; i++) {
            profile[i] = pipeline.readToken().chars().filter(ch -> ch == '#').count();
        }
        return profile;
    }

    private IntegratedMetrics computeInteractionMetrics(long[] alpha, long[] beta) {
        long totalCrossProduct = 0;
        long totalDisparityWeight = 0;

        for (int idx = 0; idx < alpha.length; idx++) {
            totalCrossProduct += (alpha[idx] * beta[idx]);
            totalDisparityWeight += Math.max(alpha[idx], beta[idx]);
        }

        return new IntegratedMetrics(totalCrossProduct, totalDisparityWeight);
    }
}

class IntegratedMetrics {
    private final long upper;
    private final long lower;

    public IntegratedMetrics(long u, long l) {
        this.upper = u;
        this.lower = l;
    }

    public long getUpperIntegrity() { return upper; }
    public long getLowerThreshold() { return lower; }
}

class FastDataPipeline {
    private final BufferedReader reader;
    private StringTokenizer tokenizer;

    public FastDataPipeline(InputStream in) {
        this.reader = new BufferedReader(new InputStreamReader(in));
    }

    public String readToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreElements()) {
            String line = reader.readLine();
            if (line == null) return null;
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    public int readInt() throws IOException {
        return Integer.parseInt(readToken());
    }
}