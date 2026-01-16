    int count = 0;
    while(startingCol < endingCol){
        for(int row = 0; row < rows; row++){
            swap(arr[row][startingCol], arr[row][endingCol]);
            startingCol++;
            endingCol--;
        }
    }