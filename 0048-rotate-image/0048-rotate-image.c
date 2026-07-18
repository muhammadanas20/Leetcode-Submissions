void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    //rotate left then up --> left then up for rotate 90degree
    int n = matrixSize;
    int last_idx = n - 1; // n-1 is the index of the last row/column

    // Outer loop: iterates through rings (i is the ring number)
    for (int i = 0; i < n / 2; i++) {
        
        // Inner loop: iterates through elements on the top side of the current ring
        // It stops before the last element of the top row which is covered by the left/right swap
        for (int j = i; j < last_idx - i; j++) {
            
            // Calculate the four indices for the current cycle
            
            // 1. Save the value of the Top-Left corner (i, j)
            int temp = matrix[i][j];

            // 2. Move element from Bottom-Left (last_idx - j, i) to Top-Left (i, j)
            matrix[i][j] = matrix[last_idx - j][i];

            // 3. Move element from Bottom-Right (last_idx - i, last_idx - j) to Bottom-Left (last_idx - j, i)
            matrix[last_idx - j][i] = matrix[last_idx - i][last_idx - j];

            // 4. Move element from Top-Right (j, last_idx - i) to Bottom-Right (last_idx - i, last_idx - j)
            matrix[last_idx - i][last_idx - j] = matrix[j][last_idx - i];

            // 5. Restore the saved Top-Left value to the Top-Right position (j, last_idx - i)
            matrix[j][last_idx - i] = temp;
    }
  }
}