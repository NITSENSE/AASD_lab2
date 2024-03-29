#include <gtest/gtest.h>
#include "src/linked_list.cc"

TEST(LinkedListTest, DefaultConstructor) {
    LinkedList<int> lst;

    EXPECT_THROW(lst.pop_head(), std::invalid_argument);
}

TEST(LinkedListTest, CopyConstructor) {
    LinkedList<int> lst1;
    lst1.push_tail(1);
    lst1.push_tail(2);
    lst1.push_tail(3);
    LinkedList<int> lst2(lst1);

    EXPECT_EQ(lst1[0], lst2[0]);
    EXPECT_EQ(lst1[1], lst2[1]);
    EXPECT_EQ(lst1[2], lst2[2]);
}


TEST(LinkedListTest, PushTail) {
    LinkedList<int> lst;
    lst.push_tail(1);
    lst.push_tail(2);

    EXPECT_EQ(lst[0], 1);
    EXPECT_EQ(lst[1], 2);
}


TEST(LinkedListTest, PushTailOther) {
    LinkedList<int> lst1;
    lst1.push_tail(1);
    lst1.push_tail(2);
    LinkedList<int> lst2;
    lst2.push_tail(3);
    lst2.push_tail(4);
    lst1.push_tail(lst2);

    EXPECT_EQ(lst1[0], 1);
    EXPECT_EQ(lst1[1], 2);
    EXPECT_EQ(lst1[2], 3);
    EXPECT_EQ(lst1[3], 4);
}


TEST(LinkedListTest, PushHead) {
    LinkedList<int> lst;
    lst.push_head(1);
    lst.push_head(2);

    EXPECT_EQ(lst[0], 2);
    EXPECT_EQ(lst[1], 1);
}

TEST(LinkedListTest, PushHeadOther) {
    LinkedList<int> lst1;
    lst1.push_head(1);
    lst1.push_head(2);
    LinkedList<int> lst2;
    lst2.push_head(3);
    lst2.push_head(4);
    lst1.push_head(lst2);

    EXPECT_EQ(lst1[0], 4);
    EXPECT_EQ(lst1[1], 3);
    EXPECT_EQ(lst1[2], 2);
    EXPECT_EQ(lst1[3], 1);
}


TEST(LinkedListTest, PopHead) {
    LinkedList<int> lst;
    lst.push_tail(1);
    lst.push_tail(2);
    lst.pop_head();

    EXPECT_EQ(lst[0], 2);
}


TEST(LinkedListTest, PopTail) {
    LinkedList<int> lst;
    lst.push_tail(1);
    lst.push_tail(2);
    lst.pop_tail();

    EXPECT_THROW(lst[1], std::invalid_argument);
}


TEST(LinkedListTest, DeleteNode) {
    LinkedList<int> lst;
    lst.push_tail(1);
    lst.push_tail(2);
    lst.push_tail(3);
    lst.delete_node(2);

    EXPECT_EQ(lst[0], 1);
    EXPECT_EQ(lst[1], 3);
}


TEST(LinkedListTest, IndexOperator) {
    LinkedList<int> lst;
    lst.push_tail(1);
    lst.push_tail(2);
    lst.push_tail(3);

    EXPECT_EQ(lst[0], 1);
    EXPECT_EQ(lst[1], 2);
    EXPECT_EQ(lst[2], 3);
}

TEST(LinkedListTest, Clear) {
    LinkedList<int> lst;
    lst.push_tail(1);
    lst.push_tail(2);
    lst.clear();

    EXPECT_THROW(lst.pop_head(), std::invalid_argument);
}
