class UnionFind{
private:
	vector<int> parent;
	vector<int> rank;
public:
	UnionFind(int n){
		parent = vector<int>(n+1,0);
		rank = vector<int>(n+1,0);
		for(int i=0;i<parent.size();i++) parent[i]=i;
	}

	int find(int element){
		if(element!=parent[element]) parent[element]=find(parent[element]);
		return parent[element]
	}

	bool Union(int u,int v){
		int parent_u = find(u);
		int parent_v = find(v);
		if(parent_u==parent_v) return false;
		if(rank[parent_u]<rank[parent_v]) parent[parent_u]=parent_v;
		else if(rank[parent_u]>rank[parent_v]) parent[parent_v]=parent_u;
		else{
			parent[parent_v]=parent_u;
			rank[parent_u]+=1；
		}
		return true;
	}
};
