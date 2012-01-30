import java.util.*;
import java.io.*;
import java.math.*;

class Block {
    public int id, cntStacks;
    public static final int MAXN = 25;
    public int [] stacks;
    public Block() {
        id = cntStacks = 0;
        stacks = new int[MAXN];
    }
    public Block (int id) {
        this.id = id;
        cntStacks = 1;
        stacks = new int[MAXN];
        Arrays.fill(stacks, 0);
        stacks[0] = id;
    }
    public int getTop() {
        if (cntStacks > 0) {
            return stacks[cntStacks - 1];
        } else {
            return -1;
        }
    }
    public boolean contains (int id) {
        for (int i = 0; i < cntStacks; ++i) {
            if (stacks[i] == id) {
                return true;
            }
        }
        return false;
    }
    public void print() {
        System.out.printf("%d:", id);
        if (cntStacks > 0) {
            for (int i = 0; i < cntStacks; ++i) {
                System.out.printf(" %d", stacks[i]);
            }
        }
        System.out.printf("\n");
    }
}

class Main {
    public static Scanner cin = new Scanner (new BufferedInputStream(System.in));
    public static final int MAXN = 25;
    public static int [] position = new int[MAXN];
    public static Block [] blocks;
    public static int moveTop(Block from, Block to) {
        if (from.getTop() == -1) {
            return -1;
        }
        position[from.getTop()] = to.id;
        return to.stacks[to.cntStacks++] = from.stacks[--from.cntStacks];
    }
    public static void returnAll(Block block, int id) {
        if (!block.contains(id)) {
            return;
        }
        while(block.getTop() != id) {
            moveTop(block, blocks[block.getTop()]);
        }
    }
    public static void main(String[] args) {
        int n = cin.nextInt();
        blocks = new Block[n];
        for (int i = 0; i < n; ++i) {
            blocks[i] = new Block(i);
            position[i] = i;
        }
        Block tmpBlock = new Block();
        while (true) {
            String command = cin.next();
            if (command.equals("quit")) {
                break;
            }
            int from = cin.nextInt();
            String action = cin.next();
            int to = cin.nextInt();
            if (from == to || from < 0 || from >= n || to < 0 || to >= n || position[from] == position[to]) {
                continue;
            }
            if (command.equals("move")) {
                if (action.equals("onto")) {
                    returnAll(blocks[position[to]], to);
                }
                returnAll(blocks[position[from]], from);
                moveTop(blocks[position[from]], blocks[position[to]]);
            } else if (command.equals("pile")) {
                if (action.equals("onto")) {
                    returnAll(blocks[position[to]], to);
                }
                while(moveTop(blocks[position[from]], tmpBlock) != from)
                    ;
                while(moveTop(tmpBlock, blocks[position[to]]) >= 0)
                    ;
            }
        }
        for (int i = 0; i < n; ++i) {
            blocks[i].print();
        }
    }
}
