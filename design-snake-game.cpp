class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food)
     : width(width), height(height), food(food) {
        if (width==0 || height==0)    return;
        
        snake.push(make_pair(0, 0));
        head = make_pair(0, 0);
         
        area = vector<vector<bool>>(height, vector<bool>(width, false));
        area[0][0] = true;
         
        fi=0;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        switch(direction[0]) {
            case 'U':
                head.first -= 1;
                break;
            case 'L':
                head.second -= 1;
                break;
            case 'R':
                head.second += 1;
                break;
            case 'D':
                head.first += 1;
                break;
        }
        
        if (head.first<0 || head.first==height || head.second<0 || head.second==width) {
            return -1;
        }
        
        if (fi >= food.size() || head.first!=food[fi].first || head.second!=food[fi].second) {
            const auto& tail = snake.front();
            area[tail.first][tail.second] = false;
            snake.pop();
        } else ++fi;
        
        if (area[head.first][head.second]) {
            return -1;
        }
        snake.push(head);
        area[head.first][head.second] = true;
        
        return fi;
    }
    
    int width, height;
    
    vector<vector<bool>> area;
  
    pair<int, int> head;
    queue<pair<int, int>> snake;
    
    vector<pair<int, int>> food;
    int fi;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */