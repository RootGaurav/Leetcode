class AllOne {
public:
    map<string, int> get_pos;
    map<int, string> get_string;
    map<string, int> appear_map;
    AllOne() {
        
    }
    void inc(string key) {
        if (appear_map.find(key) != appear_map.end()){
            appear_map[key] ++;
        }
        else{
            appear_map[key] = 1;
            get_pos[key] = appear_map.size() - 1;
            get_string[appear_map.size() - 1] = key;
        }
        int appearence = appear_map[key];
        int cur_pos = get_pos[key];
        while (cur_pos != 0){
            cout<< key << appearence << endl;
            cout<< get_string[cur_pos - 1] << appear_map[get_string[cur_pos - 1]] << endl;
            if (appearence > appear_map[get_string[cur_pos - 1]]){
                get_pos[key] = cur_pos - 1;
                get_pos[get_string[cur_pos - 1]] = cur_pos;
                get_string[cur_pos] = get_string[cur_pos - 1];
                get_string[cur_pos - 1] = key; 
                cur_pos = get_pos[key];
            }
            else{
                return;
            }
        }
    }
    
    void dec(string key) {
        appear_map[key] = max(0, appear_map[key] - 1);
        int appearence = appear_map[key];
        int cur_pos = get_pos[key];
        while (cur_pos != appear_map.size() - 1){
            if (appearence < appear_map[get_string[cur_pos + 1]]){
                get_pos[key] = cur_pos + 1;
                get_pos[get_string[cur_pos + 1]] = cur_pos;
                get_string[cur_pos] = get_string[cur_pos + 1];
                get_string[cur_pos + 1] = key; 
                cur_pos = get_pos[key];
            }
            else{
                return;
            }
        }
    }
    
    string getMaxKey() {
        for (int i = 0; i < appear_map.size(); i++){
            if (appear_map[get_string[i]] != 0){
                return get_string[i];
            }
        }
        return "";
    }
    
    string getMinKey() {
        for (int i = appear_map.size() - 1; i >= 0; i--){
            if (appear_map[get_string[i]] != 0){
                return get_string[i];
            }
        }
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */