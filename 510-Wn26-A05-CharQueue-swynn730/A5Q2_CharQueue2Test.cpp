#include "TestHarness.h"
#include "A5Q2_CharQueue2.h"


// ================================================================
TEST(CheckCapacityOfCharQueue2, CharQueue2)
{
    CharQueue2 cq1{};
    CHECK(cq1.capacity() > 0);
}

TEST(CheckSuccessfulEnqueueOfCharQueue2, CharQueue2)
{
    CharQueue2 cq1{};

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

TEST(CheckSuccessfulEnqueueBeyondCapacityOfCharQueue2, CharQueue2)
{
    CharQueue2 cq1{};

    cq1.enqueue('h');
    cq1.enqueue('e');
    cq1.enqueue('l');
    cq1.enqueue('l');
    cq1.enqueue('o');
    cq1.enqueue('!');

    CHECK(cq1.capacity() > 0);
    cq1.enqueue('!');
    cq1.enqueue('!');
    CHECK(cq1.capacity() > 0);
}

TEST(CheckSuccessfulDequeueOfCharQueue2, CharQueue2)
{
    CharQueue2 cq1{};

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

TEST(CheckSuccessfulDefaultConstructorOfCharQueue2, CharQueue2)
{
    CharQueue2 cq1{};
    cq1.enqueue('\0');
    CHECK_EQUAL('\0', cq1.dequeue());
}

TEST(CheckSuccessfulCopyConstructorOfCharQueue2, CharQueue2)
{
    CharQueue2 cq1_a{};
    cq1_a.enqueue('o');
    cq1_a.enqueue('k');
    cq1_a.enqueue('!');

    CharQueue2 cq1_b{cq1_a};

    CHECK_EQUAL('o', cq1_b.dequeue());
    CHECK_EQUAL('k', cq1_b.dequeue());
    CHECK_EQUAL('!', cq1_b.dequeue());
}

TEST(CheckSuccessfulCopyAssignmentOfCharQueue2, CharQueue2)
{
    CharQueue2 cq1_a{};
    cq1_a.enqueue('t');
    cq1_a.enqueue('e');
    cq1_a.enqueue('s');
    cq1_a.enqueue('t');

    CharQueue2 cq1_b{};

    cq1_b = cq1_a;

    CHECK_EQUAL('t', cq1_b.dequeue());
    CHECK_EQUAL('e', cq1_b.dequeue());
    CHECK_EQUAL('s', cq1_b.dequeue());
    CHECK_EQUAL('t', cq1_b.dequeue());
}

TEST(CheckSuccessfulMoveConstructorOfCharQueue2, CharQueue2)
{
    CharQueue2 cq1_a{};
    cq1_a.enqueue('s');
    CHECK(!cq1_a.isEmpty());     // has content
    CharQueue2 cq1_b{std::move(cq1_a)};
    CHECK(!cq1_b.isEmpty());     // content has been moved into
    CHECK(cq1_a.isEmpty());    // no longer has content
}

TEST(CheckSuccessfulMoveAssignmentOfCharQueue2, CharQueue2)
{
    CharQueue2 cq1_a{};
    cq1_a.enqueue('s');
    CHECK(!cq1_a.isEmpty());     // has content
    CharQueue2 cq1_b = std::move(cq1_a);
    CHECK(!cq1_b.isEmpty());     // content has been moved into
    CHECK(cq1_a.isEmpty());    // no longer has content
}
// ================================================================