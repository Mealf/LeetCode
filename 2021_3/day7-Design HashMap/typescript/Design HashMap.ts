class MyHashMap {
    table: Array<number>
    constructor() {
        this.table  = new Array<number>(1000001);
    }

    put(key: number, value: number): void {
        this.table[key] = value;
    }

    get(key: number): number {
        if(this.table[key] === undefined)
            return -1;
        return this.table[key];
    }

    remove(key: number): void {
        this.table[key] = -1;
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * var obj = new MyHashMap()
 * obj.put(key,value)
 * var param_2 = obj.get(key)
 * obj.remove(key)
 */