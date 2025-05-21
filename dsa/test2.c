A - B
|   |
C - D - E

  A  B  C  D  E
A 0  1  1  0  0
B 0  0  0  1  0
C 0  0  0  1  0
D 0  0  0  0  1
E 0  0  0  0  0

void bfs(int a[10][10], int n, int u) {
    int f, r, q[10], v;
    int s[10] = {0}; // Visited nodes tracker

    printf("The nodes visited from %d: ", u);
    f = 0, r = -1;  // Initialize queue

    q[++r] = u;     // Enqueue source node
    s[u] = 1;       // Mark source node as visited
    printf("%d ", u);

    while (f <= r) {
        u = q[f++]; // Dequeue a node
        for (v = 1; v <= n; v++) {
            if (a[u][v] == 1 && s[v] == 0) { // If v is adjacent and not visited
                printf("%d ", v);
                s[v] = 1; // Mark as visited
                q[++r] = v; // Enqueue v
            }
        }
   }
   
void dfs(int v) {
    int w;
    visited[v] = 1;
    printf("%d ", v);

    for (w = 1; w <= n; w++) {
        if (!visited[w] && a[v][w] == 1) {
            dfs(w);
        }
    }
}

void insert_hash_table(int id, char name[], EMPLOYEE a[])
{
	int i,index,h_value;
	h_value = H(id);

	for(i=0; i<HASH_SIZE; i++)
	{
		index=(h_value+i)% HASH_SIZE;
		if(a[index].id==0) //empty slot found
		{
			a[index].id=id; //insert employee id
			strcpy(a[index].name,name);
			break;
		}
	}
	if(i==HASH_SIZE) printf("Hash table full\n"); // NO empty slot
	}

[9,0,0,0,0,5,25,0,0,89]
 0 1 2 3 4 5 6 7 8 9

