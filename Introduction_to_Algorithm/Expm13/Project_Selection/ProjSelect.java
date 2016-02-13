import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class ProjSelect {   
    private static Project[] projs;
    private static BufferedReader read;
    private static Random randomGenerator;
    private static int size;
    private static int posProfits; // total positive profits
    private static double MAX = new Double(Double.POSITIVE_INFINITY); // Use this for project predecessors
    private static FlowNetwork G;
  
    public static void main(String[] args) {
        
        read = new BufferedReader(new InputStreamReader(System.in));
        
        randomGenerator = new Random();
        
        try
        {
            System.out.print("Please enter number of projects : ");
            size = Integer.parseInt(read.readLine());
     
            // create array
            projs = new Project[size];
            posProfits = 0;
            
            // Create a new FlowNetwork to pass to the FordFulkerson algorithm.
            // The FlowNetwork must have room for a source and sink, thus it is given
            // 'size + 2' instead of 'size'.  The source is index 'size' and sink is index 'size+1'.
            G = new FlowNetwork(size + 2);
            
            // Creating projects 
            for(int i=0; i<size; i++) {
            	int x = randomGenerator.nextInt(50*size);
            	x -= 50*(size-i-1);
            	if (x > 0) posProfits += x;
            	Project p = new Project(i+1, x);
            	
            	// Add an edge from source -> project if the project has a non-negative profit.
				if (x >= 0) G.addEdge(new FlowEdge(size, i, x));
				
				// Otherwise, add an edge from project -> sink.
				else G.addEdge(new FlowEdge(i, size+1, Math.abs(x)));
				
            	if (i > 0) {
            		int n = randomGenerator.nextInt(Math.min(i, 3))+1;
            		// System.out.println("n = "+n);
            		for (int j = 0; j < n; j++) {
            			int k = randomGenerator.nextInt(i);
            			if (p.predecessor.contains(projs[k]) == false) {
            				p.predecessor.add(projs[k]);
            				
            				// Add an edge from the project to its predecessor.
            				// We give it a weight of MAX so that it doesn't restrict the flow
            				// in the FlowNetwork (we only want source/sink connections to limit flow).
            				G.addEdge(new FlowEdge(i, k, MAX));
            			}
            		}
                }
                projs[i] = p;
                if (size <= 30) p.display();
            }
            System.out.println("\nThe sum of all positive profits = " + posProfits + "\n");
            System.out.println(G.toString());
        } catch(Exception ex){
            ex.printStackTrace();
        }
        
        // How to select a subset of projects such that the total profits of all selected
        // projects is maximal ? 
        // Note that if a project is selected, then all its predecessors will be selected.
        
        // First we create a new instance of the FordFulkerson.  When this happens, the implementation
        // of the F-F algorithm runs, and calculates the cut that we want.
        FordFulkerson F = new FordFulkerson(G, size, size+1);
        
        // Then check all the projects in our array.  If they are in the cut, then print the project
        // and add its profit to the total.
        double total = 0.0;
        for (int i=0; i<size; i++) {
        	if (F.inCut(i)) {
        		System.out.println(projs[i].toString());
        		total += projs[i].profit;
        	}
        }
        System.out.println("\nTotal profit = " + total);
    }
}
    
