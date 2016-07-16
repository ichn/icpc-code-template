struct ACAutomata {
    static const int maxNode = 1000000;
    static const int maxStat = 26;
    
    struct Node {
        Node*ch[maxStat];
        Node() {
            memset(ch, 0, sizeof ch);
        }
    }
}
