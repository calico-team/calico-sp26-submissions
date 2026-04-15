import java.util.*;
import java.io.*;

public class Flood
{
    static    int[] dx = new int[] { 0, 0, -1, 1};
    static int[] dy = new int[] { -1, 1, 0, 0};
    static long count = 0;
    public static void main(String[] args) throws IOException
    {
        BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));

        int testcases = Integer.parseInt(sc.readLine());

        while(testcases-- > 0)
        {
            count = 0;
            Map<Integer, Map<Integer, Boolean>> visited = new HashMap<>();
            String[] params = sc.readLine().split(" ");

            int Xg = Integer.parseInt(params[0]);
            int Yg = Integer.parseInt(params[1]);
            int Xm = Integer.parseInt(params[2]);
            int Ym = Integer.parseInt(params[3]);

            visited.put(Xg, new HashMap<>());
            visited.put(Xm, new HashMap<>());

            visited.get(Xg).put(Yg, true);
            visited.get(Xm).put(Ym, true);

            Queue<int[]> grass = new LinkedList<>();
            Queue<int[]> mycellium = new LinkedList<>();
            // Queue<int[]> retired = new LinkedList<>();


            grass.add(new int[]{Xg, Yg});
            mycellium.add(new int[]{Xm, Ym});

            Map<Integer, Map<Integer, Boolean>> retired = new HashMap<>();


            long tickCount = 2;

            while(!mycellium.isEmpty())
            {                
                if(tickCount%2 == 0 && tickCount %7 != 0)
                {
                    grass.addAll(generate(grass, visited, null, true));
                }
                if((tickCount+1)%7 == 0)
                {
                    mycellium.addAll(generate(mycellium, visited, retired, true));
                        
                }
                if((tickCount%2 == 0) && (tickCount%7 == 0))
                {
                    Queue<int[]> grassGenerated = generate(grass, visited, null, false);
                    Queue<int[]> myGenerated = generate(mycellium, visited, retired, false);

                    Queue<int[]> intersected = new LinkedList<>();

                    int mySize = myGenerated.size();

                    for(int[] g : grassGenerated)
                    {
                        visited.putIfAbsent(g[0], new HashMap<>());
                        visited.get(g[0]).put(g[1], true);
                    }

                    while(mySize-- > 0)
                    {
                        int[] my = myGenerated.poll();

                        visited.putIfAbsent(my[0], new HashMap<>());

                        if(visited.get(my[0]).getOrDefault(my[1], false))
                            intersected.add(my);
                        else
                        {
                            mycellium.add(my);
                            visited.get(my[0]).put(my[1], true);
                        }
                    }

                    grass.addAll(grassGenerated);
                    // mycellium.addAll(myGenerated);

                    grass.addAll(intersected);
                }

                tickCount+=2;
            }


            System.out.println(count);
            
        }
    }


    public static Queue<int[]> generate(Queue<int[]> curr, Map<Integer, Map<Integer, Boolean>> visited, Map<Integer, Map<Integer, Boolean>> retired, boolean change)
    {
        int size = curr.size();
        Queue<int[]> queue = new LinkedList<>();
        while(size-- > 0)
        {
            int[] grassCoords = curr.poll();

            boolean grew = false;

                for(int i = 0; i < dx.length; i++)
                {


                    // if((dir_x != 0 && dir_y != 0)) continue;

                    int x = grassCoords[0]+dx[i];
                    int y = grassCoords[1]+dy[i];

                    // if(x == grassCoords[0] && y == grassCoords[1]) continue;

                    visited.putIfAbsent(x, new HashMap<>());

                    if(!visited.get(x).getOrDefault(y, false))
                    {
                        grew = true;
                        if(change) visited.get(x).put(y, true);
                        queue.add(new int[]{x,y});
                    }
                }
            // if(grew) curr.add(grassCoords);
            if(retired != null) 
            {
                // System.out.println(Arrays.toString(grassCoords));
                retired.putIfAbsent(grassCoords[0], new HashMap<>());
                if(retired.get(grassCoords[0]).get(grassCoords[1]) == null) count++;
                retired.get(grassCoords[0]).put(grassCoords[1], true);
            }
            
        }

        return queue;
    }
}