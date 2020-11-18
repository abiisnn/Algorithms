bool judgeCircle(string moves) {
    int x = 0, y = 0;
    for(int i = 0; i < int(moves.size()); i++) {
        if(moves[i] == 'R') {
            x++;
        } else if(moves[i] == 'L') {
            x--;
        } else if(moves[i] == 'U') {
            y++;
        } else {
            y--;
        }
    }
    return (!x && !y);
}