from collections import OrderedDict

class LRUCache:

    def __init__(self, capacity: int):
        self.cache = OrderedDict()
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        # Move the accessed key to the end to show it was recently used
        self.cache.move_to_end(key)
        return self.cache[key]

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            # Update value and move to the end
            self.cache.move_to_end(key)
        self.cache[key] = value
        
        # Evict the oldest item if capacity is exceeded
        if len(self.cache) > self.capacity:
            self.cache.popitem(last=False) # last=False pops the first (oldest) item
