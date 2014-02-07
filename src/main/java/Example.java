import net.imglib2.paramaxflow.Parametric;
import net.imglib2.paramaxflow.Region;

public class Example
{
	// print cut C_k (0<=k<=N where N is the number returned by Solve()).
	static void PrintCut(final Parametric p, final long nodeNum, final long k)
	{
		int i;

		System.out.printf("Cut (");
		for (i=0; i<nodeNum; i++)
		{
			final int x = (p.GetRegionCount(p.GetRegion(i)) >= k) ? 1 : 0; // label of node i in C_k
			System.out.printf(" %d ", x);
		}
		System.out.printf(")");
	}

	public static void main( final String... args ) throws Exception
	{
		long k, N;
		final long nodeNum = 3;
		Region r;
		final Parametric p = new Parametric(/*maximum # of nodes*/ 3, /*maximum # of edges*/ 2);
		final double lambdaMin = -10, lambdaMax = 10;

		p.AddNode(3); // add 3 nodes; their id's are 0,1,2

		p.AddUnaryTerm(/* NodeId */ 0,    2, -1); // add term   (2 lambda - 1) x
		p.AddUnaryTerm(/* NodeId */ 1,    1, 2);  // add term   (lambda + 2) y
		p.AddUnaryTerm(/* NodeId */ 2,    0, 3);  // add term   3 z

		p.AddPairwiseTerm(/* NodeId */ 0, /* NodeId */ 1,     0, 1, 1, 0);  // add term   |y - x|
		p.AddPairwiseTerm(/* NodeId */ 1, /* NodeId */ 2,     0, 0, 0, -1);  // add term   - y z

		N = p.Solve(lambdaMin, lambdaMax);

		// consider cut C_0
		r = p.GetFirstRegion();
		if (p.GetRegionLambda(r) > lambdaMin)
		{
			PrintCut(p, nodeNum, 0);
			System.out.printf(" : optimal for lambda's in (-infinity; %f]\n", p.GetRegionLambda(r));
		}

		// Consider cuts C_0,...,C_{N-1}
		for (k=1; k<N; k++, r=p.GetNextRegion(r))
		{
			PrintCut(p, nodeNum, k);
			System.out.printf(" : optimal for lambda's in [%f; %f]\n", p.GetRegionLambda(r), p.GetRegionLambda(p.GetNextRegion(r)));
		}

		// consider cut C_N
		r = p.GetLastRegion();
		if (p.GetRegionLambda(r) < lambdaMax)
		{
			PrintCut(p, nodeNum, N);
			System.out.printf(" : optimal for lambda's in [%f; +infinity)\n", p.GetRegionLambda(r));
		}
	}
}
