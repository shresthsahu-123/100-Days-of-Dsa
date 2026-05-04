bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    int visited[roomsSize];
    for (int i = 0; i < roomsSize; i++) visited[i] = 0;

    // Stack for DFS
    int stack[roomsSize];
    int top = -1;

    // Start from room 0
    stack[++top] = 0;

    while (top != -1) {
        int room = stack[top--];

        if (visited[room]) continue;
        visited[room] = 1;

        // Pick up all keys in this room and add to stack
        for (int i = 0; i < roomsColSize[room]; i++) {
            int key = rooms[room][i];
            if (!visited[key])
                stack[++top] = key;
        }
    }

    // Check if all rooms were visited
    for (int i = 0; i < roomsSize; i++)
        if (!visited[i]) return false;

    return true;
}
