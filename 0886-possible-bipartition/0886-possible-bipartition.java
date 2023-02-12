import java.util.ArrayList;
import java.util.List;

class Solution {
    private int[] parent;

    public int find(int p) {
        int root = p;
        while (root != parent[root]) {
            root = parent[root];
        }

        while (parent[p] != root) {
            int next = parent[p];
            parent[p] = root;
            p = next;
        }

        return root;
    }

    public void unify(int p, int q) {
        int parent_p = find(p);
        int parent_q = find(q);

        if (parent_p != parent_q) {
            parent[parent_q] = parent_p;
        }
    }

    public boolean possibleBipartition(int n, int[][] dislikes) {
        // Make adjacency list
        List<List<Integer>> graph = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        int m = dislikes.length;
        for (int i = 0; i < m; i++) {
            int u = dislikes[i][0] - 1;
            int v = dislikes[i][1] - 1;
            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        // Disjoint sets
        parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (int u = 0; u < n; u++) {
            List<Integer> nodes = graph.get(u);
            for (int v : nodes) {
                int v0 = nodes.get(0);
                if (find(u) == find(v)) {
                    return false;
                }
                unify(v, v0);
            }
        }
        return true;
    }
}
