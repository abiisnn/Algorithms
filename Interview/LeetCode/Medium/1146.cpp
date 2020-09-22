class SnapshotArray {
private:
    int version;
    vector<vector<pair<int, int>>> adj;
public:
    SnapshotArray(int length) {
        version = 0;
        adj.assign(length, vector<pair<int, int>>(1, make_pair(0, 0)));
    }
    void set(int index, int val) {
        int lastVersion = adj[index][adj[index].size() - 1].first;
        if(lastVersion == version) {
            adj[index][adj[index].size() - 1].second = val;
        } else {
            adj[index].push_back(make_pair(version, val));
        }
    }
    int snap() {
        return version++;
    }
    int get(int index, int snap_id) {
        int l = 0, r = adj[index].size() - 1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(adj[index][m].first < snap_id) l = m + 1; 
            else if(adj[index][m].first > snap_id) r = m - 1;
            else l = m + 1;
        }
        return adj[index][--l].second; 
    }
};
/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */