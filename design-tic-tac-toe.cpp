class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n): n(n), diagonal_scores({{0}}) {
        scores[1] = scores[0] = vector<vector<int>>(2, vector<int>(n, 0));
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        --player;
        if (++scores[player][0][row] == n) return player+1;
        if (++scores[player][1][col] == n) return player+1;
        if ((row==col) && (++diagonal_scores[player][0]) == n) return player+1;
        if ((row==n-col-1) && (++diagonal_scores[player][1]) == n) return player+1;
        return 0;
    }
    
    int n;
    vector<vector<int>> scores[2]; // 0: row, 1: col
    int diagonal_scores[2][2]; // 0: ul-dr, 1: ur-dl
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
