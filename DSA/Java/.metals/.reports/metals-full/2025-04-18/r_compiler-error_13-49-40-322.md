file://<WORKSPACE>/test/dsa/lib/LibTestFX.java
### java.util.NoSuchElementException: next on empty iterator

occurred in the presentation compiler.

presentation compiler configuration:


action parameters:
uri: file://<WORKSPACE>/test/dsa/lib/LibTestFX.java
text:
```scala
package dsa.lib;

import dsa.lib.arrays.ArrayInt;
import dsa.lib.lists.linkedlists.SinglyLinkedList;
import dsa.lib.trees.BinaryTree;
import dsa.nodes.BinaryTreeNode;
import dsa.nodes.ListNode;

public class LibTestFX {
    public static BinaryTreeNode arrayToBinaryTree(int... ary) {
        return new ArrayInt(ary).toBinaryTree();
    }

    public static ListNode arrayToSinglyLinkedlist(int[] ary) {
        return new ArrayInt(ary).toSinglyLinkedList();
    }

    public static ListNode arrayToCyclicSinglyLinkedlist(int[] ary, int pos) {
        return new ArrayInt(ary).toCyclicSinglyLinkedList(pos);
    }

    public static ListNode getLinkedListNodeByIndex(ListNode head, int idx) {
        return new SinglyLinkedList(head).getNodeByIndex(idx);
    }

    public static ListNode getLinkedListNodeByValue(ListNode head, int val) {
        return new SinglyLinkedList(head).getNodeByValue(val);
    }

    public static BinaryTreeNode getTreeNodeByIndex(BinaryTreeNode root, int idx) {
        return new BinaryTree(root).getNodeByIndex(idx);
    }

    public static BinaryTreeNode getTreeNodeByValue(BinaryTreeNode root, int val) {
        return new BinaryTree(root).getNodeByValue(val);
    }
}

```



#### Error stacktrace:

```
scala.collection.Iterator$$anon$19.next(Iterator.scala:973)
	scala.collection.Iterator$$anon$19.next(Iterator.scala:971)
	scala.collection.mutable.MutationTracker$CheckedIterator.next(MutationTracker.scala:76)
	scala.collection.IterableOps.head(Iterable.scala:222)
	scala.collection.IterableOps.head$(Iterable.scala:222)
	scala.collection.AbstractIterable.head(Iterable.scala:935)
	dotty.tools.dotc.interactive.InteractiveDriver.run(InteractiveDriver.scala:164)
	dotty.tools.pc.CachingDriver.run(CachingDriver.scala:45)
	dotty.tools.pc.WithCompilationUnit.<init>(WithCompilationUnit.scala:31)
	dotty.tools.pc.SimpleCollector.<init>(PcCollector.scala:351)
	dotty.tools.pc.PcSemanticTokensProvider$Collector$.<init>(PcSemanticTokensProvider.scala:63)
	dotty.tools.pc.PcSemanticTokensProvider.Collector$lzyINIT1(PcSemanticTokensProvider.scala:63)
	dotty.tools.pc.PcSemanticTokensProvider.Collector(PcSemanticTokensProvider.scala:63)
	dotty.tools.pc.PcSemanticTokensProvider.provide(PcSemanticTokensProvider.scala:88)
	dotty.tools.pc.ScalaPresentationCompiler.semanticTokens$$anonfun$1(ScalaPresentationCompiler.scala:111)
```
#### Short summary: 

java.util.NoSuchElementException: next on empty iterator