import java.io.*;
import java.math.*;
import java.util.*;

public class Main implements Runnable {

	final String filename = "in";

	public static void main(String[] args) {
		// new Thread(new Main()).start();
		new Thread(null, new Main(), "1", 1 << 25).start();

	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new BufferedWriter(new OutputStreamWriter(System.out));
			// in = new BufferedReader(new FileReader(filename));
			// out = new BufferedWriter(new FileWriter(filename+".out"));
			int kase = iread();
			for (int i = 1; i <= kase; ++i) {
				solve(i);
			}
			out.flush();
		} catch (Exception e) {
			//e.printStackTrace();
			System.exit(1);
		}
	}

	public void solve(int kaseno) throws Exception {
		int nth=iread();
		Matrix A = new Matrix(4, 4);
		A.data[0][0]=0;A.data[0][1]=1;A.data[0][2]=1;A.data[0][3]=1;
		A.data[1][0]=1;A.data[1][1]=0;A.data[1][2]=1;A.data[1][3]=1;
		A.data[2][0]=1;A.data[2][1]=1;A.data[2][2]=0;A.data[2][3]=1;
		A.data[3][0]=1;A.data[3][1]=0;A.data[3][2]=1;A.data[3][3]=1;
		
		Matrix B = A.Pow(A, nth-2);
		//B.Print();
		long retval = domod( B.data[0][2]* (long)12 );
		out.write( retval+"\n" );
	}

	public class Matrix {

		long[][] data;
		int row;
		int col;

		public Matrix(int rowCount, int colCount) {
			this.row = rowCount;
			this.col = colCount;
			this.data = new long[rowCount][colCount];
			for(int i=0;i<rowCount;++i){
				Arrays.fill(this.data[0], 0);
			}
		}

		public Matrix Multiply(Matrix A, Matrix B) {
			Matrix result = new Matrix(A.row, B.col);
			for (int i = 0; i < A.row; ++i) {
				for (int j = 0; j < B.row; ++j) {
					for (int k = 0; k < B.col; ++k) {
						long var = domod(A.data[i][j] * B.data[j][k]);
						result.data[i][k] = domod(result.data[i][k] + var);
					}
				}
			}
			return result;
		}

		public Matrix Pow(Matrix A, int pow) {
			Matrix res = A;
			while (pow > 0) {
				if ((pow & 1) != 0) {
					res = Multiply(res, A);
				}
				A = Multiply(A, A);
				pow >>= 1;
			}
			return res;
		}

		public void Print() {
			for (int i = 0; i < row; ++i) {
				debug(data[i]);
			}
		}
	}

	final long mod = 1000000007;
	public long domod(long var) {
		if (var < 0) {
			var += mod;
		}
		return var % mod;
	}
	public void debug(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}

	public int iread() throws Exception {
		return Integer.parseInt(readword());
	}

	public double dread() throws Exception {
		return Double.parseDouble(readword());
	}

	public long lread() throws Exception {
		return Long.parseLong(readword());
	}

	BufferedReader in;
	BufferedWriter out;

	public String readword() throws IOException {
		StringBuilder b = new StringBuilder();
		int c;
		c = in.read();
		while (c >= 0 && c <= ' ') {
			c = in.read();
		}
		if (c < 0) {
			return "";
		}
		while (c > ' ') {
			b.append((char) c);
			c = in.read();
		}
		return b.toString();
	}
}
