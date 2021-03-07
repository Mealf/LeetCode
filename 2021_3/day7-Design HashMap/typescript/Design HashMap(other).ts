class MyHashMap {
    
    private bucket: number[] = [];
    
    constructor() {

    }

    put(key: number, value: number): void {
        let hash = this.hash(key);
        this.bucket[hash] = value;
    }

    get(key: number): number {
        let hash = this.hash(key);
        return this.bucket[hash] === undefined ? -1 : this.bucket[hash];
    }

    remove(key: number): void {
        let hash = this.hash(key);
        this.bucket[hash] = undefined;
    }

    hash(key: number): number {
        return key;
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * var obj = new MyHashMap()
 * obj.put(key,value)
 * var param_2 = obj.get(key)
 * obj.remove(key)
 */