package lib.trees;

public interface Graph extends Tree {
    @Override
    default int size() {
        // ToDo
        return 0;
    }
}
