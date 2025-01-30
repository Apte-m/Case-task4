// Определение классов
template <typename T>
class Queue {
public:
    virtual void push(const T& value) = 0;
    virtual T pop() = 0;
    virtual bool isEmpty() const = 0;
    virtual ~Queue() = default;
};

template <typename T>
class Heap {
public:
    virtual void push(const T& value) = 0;
    virtual T pop() = 0;
    virtual bool isEmpty() const = 0;
    virtual ~Heap() = default;
};

template <typename T>
class BinaryTree {
public:
    virtual void push(const T& value) = 0;
    virtual bool pop(const T& value) = 0;
    virtual bool search(const T& value) const = 0;
    virtual bool isEmpty() const = 0;
    virtual ~BinaryTree() = default;
};

// Юнит-тесты
#include <gtest/gtest.h>

// Тесты для Queue
class QueueTest : public ::testing::Test {
protected:
    Queue<int>* queue;

    void SetUp() override {
        queue = new ConcreteQueue<int>();  // Конкретная реализация
    }

    void TearDown() override {
        delete queue;
    }
};

TEST_F(QueueTest, PushTest) {
    EXPECT_TRUE(queue->isEmpty());
    queue->push(1);
    EXPECT_FALSE(queue->isEmpty());
}

TEST_F(QueueTest, PopTest) {
    queue->push(1);
    queue->push(2);
    EXPECT_EQ(queue->pop(), 1);
    EXPECT_EQ(queue->pop(), 2);
    EXPECT_TRUE(queue->isEmpty());
}

TEST_F(QueueTest, EmptyPopTest) {
    EXPECT_THROW(queue->pop(), std::runtime_error);
}

// Тесты для Heap
class HeapTest : public ::testing::Test {
protected:
    Heap<int>* heap;

    void SetUp() override {
        heap = new ConcreteHeap<int>();  // Конкретная реализация
    }

    void TearDown() override {
        delete heap;
    }
};

TEST_F(HeapTest, PushTest) {
    EXPECT_TRUE(heap->isEmpty());
    heap->push(1);
    EXPECT_FALSE(heap->isEmpty());
}

TEST_F(HeapTest, PopTest) {
    heap->push(3);
    heap->push(1);
    heap->push(2);
    EXPECT_EQ(heap->pop(), 3);  // Предполагая max-heap
    EXPECT_EQ(heap->pop(), 2);
    EXPECT_EQ(heap->pop(), 1);
}

TEST_F(HeapTest, EmptyPopTest) {
    EXPECT_THROW(heap->pop(), std::runtime_error);
}

// Тесты для BinaryTree
class BinaryTreeTest : public ::testing::Test {
protected:
    BinaryTree<int>* tree;

    void SetUp() override {
        tree = new ConcreteBinaryTree<int>();  // Конкретная реализация
    }

    void TearDown() override {
        delete tree;
    }
};

TEST_F(BinaryTreeTest, PushTest) {
    EXPECT_TRUE(tree->isEmpty());
    tree->push(1);
    EXPECT_FALSE(tree->isEmpty());
}

TEST_F(BinaryTreeTest, SearchTest) {
    tree->push(1);
    tree->push(2);
    tree->push(3);
    EXPECT_TRUE(tree->search(2));
    EXPECT_FALSE(tree->search(4));
}

TEST_F(BinaryTreeTest, PopTest) {
    tree->push(1);
    tree->push(2);
    EXPECT_TRUE(tree->pop(1));
    EXPECT_FALSE(tree->search(1));
    EXPECT_FALSE(tree->pop(3));
}

TEST_F(BinaryTreeTest, EmptySearchTest) {
    EXPECT_FALSE(tree->search(1));
}
