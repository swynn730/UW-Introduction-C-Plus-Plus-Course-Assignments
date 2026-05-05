#include "TestHarness.h"
#include "A5Q1_CharQueue1.h"


// ================================================================
TEST(CheckCapacityOfCharQueue1, CharQueue1)
{
    CharQueue1 cq1{6};
    CHECK_EQUAL(6, cq1.capacity());
}

TEST(CheckSuccessfulEnqueueOfCharQueue1, CharQueue1)
{
    CharQueue1 cq1{};

    cq1.enqueue('h');
    cq1.enqueue('e');
    cq1.enqueue('l');
    cq1.enqueue('l');
    cq1.enqueue('o');

    CHECK_EQUAL('h', cq1.dequeue());
    CHECK_EQUAL('e', cq1.dequeue());
    CHECK_EQUAL('l', cq1.dequeue());
    CHECK_EQUAL('l', cq1.dequeue());
    CHECK_EQUAL('o', cq1.dequeue());
}

TEST(CheckSuccessfulEnqueueBeyondCapacityOfCharQueue1, CharQueue1)
{
    CharQueue1 cq1{};
    
    cq1.enqueue('h');
    cq1.enqueue('e');
    cq1.enqueue('l');
    cq1.enqueue('l');
    cq1.enqueue('o');
    cq1.enqueue('!');

    CHECK_EQUAL(7, cq1.capacity());
    cq1.enqueue('!');
    cq1.enqueue('!');
    CHECK_EQUAL(9, cq1.capacity());
}

TEST(CheckSuccessfulDequeueOfCharQueue1, CharQueue1)
{
    CharQueue1 cq1{};

    cq1.enqueue('h');
    cq1.enqueue('e');
    cq1.enqueue('l');
    cq1.enqueue('l');
    cq1.enqueue('o');

    CHECK_EQUAL('h', cq1.dequeue());
    CHECK_EQUAL('e', cq1.dequeue());
    CHECK_EQUAL('l', cq1.dequeue());
    CHECK_EQUAL('l', cq1.dequeue());
    CHECK_EQUAL('o', cq1.dequeue());
}

TEST(CheckSuccessfulDefaultConstructorOfCharQueue1, CharQueue1)
{
    CharQueue1 cq1{};
    cq1.enqueue('\0');
    CHECK_EQUAL('\0', cq1.dequeue());
}

TEST(CheckSuccessfulCopyConstructorOfCharQueue1, CharQueue1)
{
    CharQueue1 cq1_a{};
    cq1_a.enqueue('o');
    cq1_a.enqueue('k');
    cq1_a.enqueue('!');

    CharQueue1 cq1_b{cq1_a};

    CHECK_EQUAL('o', cq1_b.dequeue());
    CHECK_EQUAL('k', cq1_b.dequeue());
    CHECK_EQUAL('!', cq1_b.dequeue());
}

TEST(CheckSuccessfulCopyAssignmentOfCharQueue1, CharQueue1)
{
    CharQueue1 cq1_a{};
    cq1_a.enqueue('t');
    cq1_a.enqueue('e');
    cq1_a.enqueue('s');
    cq1_a.enqueue('t');

    CharQueue1 cq1_b{};

    cq1_b = cq1_a;

    CHECK_EQUAL('t', cq1_b.dequeue());
    CHECK_EQUAL('e', cq1_b.dequeue());
    CHECK_EQUAL('s', cq1_b.dequeue());
    CHECK_EQUAL('t', cq1_b.dequeue());
}

TEST(CheckSuccessfulMoveConstructorOfCharQueue1, CharQueue1)
{
    CharQueue1 cq1_a{};
    cq1_a.enqueue('s');
    CHECK(!cq1_a.isEmpty());     // has content
    CharQueue1 cq1_b{std::move(cq1_a)};
    CHECK(!cq1_b.isEmpty());     // content has been moved into
    CHECK(cq1_a.isEmpty());    // no longer has content
}

TEST(CheckSuccessfulMoveAssignmentOfCharQueue1, CharQueue1)
{
    CharQueue1 cq1_a{};
    cq1_a.enqueue('s');
    CHECK(!cq1_a.isEmpty());     // has content
    CharQueue1 cq1_b = std::move(cq1_a);
    CHECK(!cq1_b.isEmpty());     // content has been moved into
    CHECK(cq1_a.isEmpty());    // no longer has content
}
// ================================================================