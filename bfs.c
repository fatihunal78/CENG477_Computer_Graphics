#include <stdio.h>


typedef struct
{
  int u, v;
  int l;
} edge;

typedef struct edgeref_struct
{
  int edge_id;
  struct edgeref_struct *next;
} edgeref;


typedef struct
{
  int d;
  int parent;
  edgeref *edges;
} vertex;

#define QINS(val) queue[qhead++] = val
#define QPOP      queue[qtail++]
#define QEMPTY    (qhead == qtail)

main(int argc, char *argv[])
{
  int num_v, num_e;
  vertex *v;
  edge   *e;
  edgeref *er;
  int    i, u_idx, v_idx, l;
  int    ei, eri;
  int    *queue, qhead, qtail;


  scanf("%d %d", &num_v, &num_e);
  v = (vertex *) malloc(num_v * sizeof(vertex));
  e = (edge   *) malloc(num_e * sizeof(edge));
  er = (edgeref *) malloc(num_e * 2 * sizeof(edgeref));
  queue = (int *) malloc(num_v * sizeof(int));

  for (i = 0; i < num_v; ++i)
    {
      v[i].edges = NULL;
      v[i].d = -1;
    }

  /* Read in the edges */
  ei = eri = 0;
  for (i = 0; i < num_e; ++i)
    {
      scanf("%d %d %d", &u_idx, &v_idx, &l);
      e[ei].u = u_idx;
      e[ei].v = v_idx;
      e[ei].l = l;

      /* Add this edge to vertex U and V */
      er[eri].edge_id = ei;
      er[eri].next = v[u_idx].edges;
      v[u_idx].edges = &er[eri];
      ++eri;

      er[eri].edge_id = ei;
      er[eri].next = v[v_idx].edges;
      v[v_idx].edges = &er[eri];
      ++eri;

      ++ei;
    }

  printf("Built the graph  -- %d verts, %d edges\n", num_v, num_e);

  qhead = qtail = 0;
  QINS(0);
  v[0].d = 0;
  while (!QEMPTY)
    {
      edgeref *tmp;

      u_idx = QPOP;
      printf("Expand from vertex %d, distance %d\n",
	     u_idx, v[u_idx].d);

      for (tmp = v[u_idx].edges; tmp != NULL; tmp = tmp->next)
	{
	  printf("Check edge from %d to %d:  \n",
		 e[tmp->edge_id].u,
		 e[tmp->edge_id].v);

	  if (e[tmp->edge_id].u == u_idx)
	    v_idx = e[tmp->edge_id].v;
	  else
	    v_idx = e[tmp->edge_id].u;

	  printf("Connects to %d\n", v_idx);

	  if (v[v_idx].d == -1)
	    {
	      v[v_idx].d = v[u_idx].d + 1;
	      QINS(v_idx);
	      printf("  Discovered vertex %d, distance == %d\n",
		     v_idx, v[v_idx].d);
	    }
	  else
	    printf("  Vertex %d already discovered\n", v_idx);
	}
    }
}
