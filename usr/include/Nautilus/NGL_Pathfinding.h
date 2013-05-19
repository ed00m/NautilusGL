using namespace std;

#define ngl_max_route 65000

unsigned char ngl_pathfinding;

class ngl_route 
{
	public:
		unsigned int index;
		
		struct ngl_route_stack {
			unsigned char x;
			unsigned char y;
		} ngl_route_data[ngl_max_route];
		
		ngl_route();
		~ngl_route();
		
		void reset(void);
		unsigned char add(unsigned char new_x, unsigned char new_y);
		unsigned int number(void);
		
		unsigned char get_x(unsigned int number);
		unsigned char get_y(unsigned int number);
};

ngl_route::ngl_route()
{
	index=0;
}

ngl_route::~ngl_route()
{

}

void
ngl_route::reset()
{
	index=0;
}

unsigned char
ngl_route::add(unsigned char new_x, unsigned char new_y)
{
	if (index<ngl_max_route) {
		ngl_route_data[index].x=new_x;
		ngl_route_data[index].y=new_y;
		index++;
		
		return 0; // Ok
	}
	
	return 1; // Error, ruta llena
}

unsigned int
ngl_route::number(void)
{
	return index;
}

unsigned char
ngl_route::get_x(unsigned int number)
{
	return ngl_route_data[number].x;
}

unsigned char
ngl_route::get_y(unsigned int number)
{
	return ngl_route_data[number].y;
}

const int ngl_n=255;
const int ngl_m=255;
static int ngl_map[ngl_n][ngl_m];
static int ngl_closed_nodes_map[ngl_n][ngl_m];
static int ngl_open_nodes_map[ngl_n][ngl_m];
static int ngl_dir_map[ngl_n][ngl_m];
const int ngl_dir=8;
static int ngl_dx[ngl_dir]={1, 1, 0, -1, -1, -1, 0, 1};
static int ngl_dy[ngl_dir]={0, 1, 1, 1, 0, -1, -1, -1};

class ngl_nodep
{
    // current position
    int xPos;
    int yPos;
    // total distance already travelled to reach the node
    int level;
    // priority=level+remaining distance estimate
    int priority;  // smaller: higher priority

    public:
        ngl_nodep(int xp, int yp, int d, int p) 
            {xPos=xp; yPos=yp; level=d; priority=p;}
    
        int getxPos() const {return xPos;}
        int getyPos() const {return yPos;}
        int getLevel() const {return level;}
        int getPriority() const {return priority;}

        void updatePriority(const int & xDest, const int & yDest)
        {
             priority=level+estimate(xDest, yDest)*10; //A*
        }

        // give better priority to going strait instead of diagonally
        void nextLevel(const int & i) // i: direction
        {
             level+=(ngl_dir==8?(i%2==0?10:14):10);
        }
        
        // Estimation function for the remaining distance to the goal.
        const int & estimate(const int & xDest, const int & yDest) const
        {
            static int xd, yd, d;
            xd=xDest-xPos;
            yd=yDest-yPos;
				
				// Sin metodo seleccionado
				if (!ngl_pathfinding) {
					ngl_pathfinding=2;
				}

				switch (ngl_pathfinding)
				{
					case 1:
						d=static_cast<int>(sqrt(xd*xd+yd*yd)); // Euclidian Distance
					break;

					case 2:
						d=abs(xd)+abs(yd); // Manhattan distance
					break;
            
					case 3:
						d=max(abs(xd), abs(yd)); // Chebyshev distance
					break;
				}

            return(d);
        }
};

// Determine priority (in the priority queue)
bool operator<(const ngl_nodep & a, const ngl_nodep & b)
{
  return a.getPriority() > b.getPriority();
}

// A-star algorithm.
// The route returned is a string of direction digits.
ngl_route
ngl_path_find( const int & xStart, const int & yStart, 
                 const int & xFinish, const int & yFinish )
{
    static priority_queue<ngl_nodep> pq[2]; // list of open (not-yet-tried) nodes
    static int pqi; // pq index
    static ngl_nodep* n0;
    static ngl_nodep* m0;
    static int i, j, x, y, xdx, ydy;
    static char c;
    pqi=0;

    // reset the node maps
    for(y=0;y<ngl_m;y++)
    {
        for(x=0;x<ngl_n;x++)
        {
            ngl_closed_nodes_map[x][y]=0;
            ngl_open_nodes_map[x][y]=0;
        }
    }

    // create the start node and push into list of open nodes
    n0=new ngl_nodep(xStart, yStart, 0, 0);
    n0->updatePriority(xFinish, yFinish);
    pq[pqi].push(*n0);
    ngl_open_nodes_map[x][y]=n0->getPriority(); // mark it on the open nodes map

    // A* search
    while(!pq[pqi].empty())
    {
        // get the current node w/ the highest priority
        // from the list of open nodes
        n0=new ngl_nodep( pq[pqi].top().getxPos(), pq[pqi].top().getyPos(), 
                     pq[pqi].top().getLevel(), pq[pqi].top().getPriority());

        x=n0->getxPos(); y=n0->getyPos();

        pq[pqi].pop(); // remove the node from the open list
        ngl_open_nodes_map[x][y]=0;
        // mark it on the closed nodes map
        ngl_closed_nodes_map[x][y]=1;

        // quit searching when the goal state is reached
        //if((*n0).estimate(xFinish, yFinish) == 0)
        if(x==xFinish && y==yFinish) 
        {
            // generate the path from finish to start
            // by following the directions
            string path="";
            while(!(x==xStart && y==yStart))
            {
                j=ngl_dir_map[x][y];
                c='0'+(j+ngl_dir/2)%ngl_dir;
                path=c+path;
                x+=ngl_dx[j];
                y+=ngl_dy[j];
            }

            // garbage collection
            delete n0;
            // empty the leftover nodes
            while(!pq[pqi].empty()) pq[pqi].pop();           
            //return path; // POSIBLE RUTA ENCONTRADA

				ngl_route camino;
				camino.reset();
	
				if(path.length()>0)
				{
					int j; char c;
					int x=xStart;
					int y=yStart;
					ngl_map[x][y]=2;
		
					for(int i=0;i<path.length();i++)
					{
						c=path.at(i);
						j=atoi(&c); 
						x=x+ngl_dx[j];
						y=y+ngl_dy[j];
						camino.add(x, y);
					}

					ngl_map[x][y]=4;
					return camino;
				}
        }

        // generate moves (child nodes) in all possible directions
        for(i=0;i<ngl_dir;i++)
        {
            xdx=x+ngl_dx[i]; ydy=y+ngl_dy[i];

            if(!(xdx<0 || xdx>ngl_n-1 || ydy<0 || ydy>ngl_m-1 || ngl_map[xdx][ydy]==1 
                || ngl_closed_nodes_map[xdx][ydy]==1))
            {
                // generate a child node
                m0=new ngl_nodep( xdx, ydy, n0->getLevel(), 
                             n0->getPriority());
                m0->nextLevel(i);
                m0->updatePriority(xFinish, yFinish);

                // if it is not in the open list then add into that
                if(ngl_open_nodes_map[xdx][ydy]==0)
                {
                    ngl_open_nodes_map[xdx][ydy]=m0->getPriority();
                    pq[pqi].push(*m0);
                    // mark its parent node direction
                    ngl_dir_map[xdx][ydy]=(i+ngl_dir/2)%ngl_dir;
                }
                else if(ngl_open_nodes_map[xdx][ydy]>m0->getPriority())
                {
                    // update the priority info
                    ngl_open_nodes_map[xdx][ydy]=m0->getPriority();
                    // update the parent direction info
                    ngl_dir_map[xdx][ydy]=(i+ngl_dir/2)%ngl_dir;

                    // replace the node
                    // by emptying one pq to the other one
                    // except the node to be replaced will be ignored
                    // and the new node will be pushed in instead
                    while(!(pq[pqi].top().getxPos()==xdx && 
                           pq[pqi].top().getyPos()==ydy))
                    {                
                        pq[1-pqi].push(pq[pqi].top());
                        pq[pqi].pop();       
                    }
                    pq[pqi].pop(); // remove the wanted node
                    
                    // empty the larger size pq to the smaller one
                    if(pq[pqi].size()>pq[1-pqi].size()) pqi=1-pqi;
                    while(!pq[pqi].empty())
                    {                
                        pq[1-pqi].push(pq[pqi].top());
                        pq[pqi].pop();       
                    }
                    pqi=1-pqi;
                    pq[pqi].push(*m0); // add the better node instead
                }
                else delete m0; // garbage collection
            }
        }
        delete n0; // garbage collection
    }
    
    //return ""; // no route found
}


ngl_route
ngl_path_set(string route, unsigned char xA, unsigned char yA)
{
	ngl_route camino;
	
	if(route.length()>0)
   {
		int j; char c;
		int x=xA;
		int y=yA;
		ngl_map[x][y]=2;
		
		for(int i=0;i<route.length();i++)
		{
			c=route.at(i);
			j=atoi(&c); 
			x=x+ngl_dx[j];
			y=y+ngl_dy[j];
			//ngl_map[x][y]=3;
			camino.add(x, y);
		}
		
		ngl_map[x][y]=4;
		return camino;
	}
}

void
ngl_blocks(ngl_entity *zone)
{
	unsigned int lx, ly, lc;
	
	lx=0;
	while (lx<255)
	{
		 ly=0;
		while (ly<255) {
			 ngl_map[lx][ly]=0; // Baldosa
			 lc=ngl_get_pixel_r(zone, lx, ly);
			 if (lc==0) {
				 ngl_map[lx][ly]=1; // Pared
			 }
			 
			ly++; 
		 }
		 lx++;
	 }
}
