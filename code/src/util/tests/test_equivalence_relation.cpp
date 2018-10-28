
#include <catch.hpp>
#include "../equivalence_relation.h"

using namespace tollk;

EquivalenceRelation<unsigned char> TestEquivRelation1();
tollk::EquivalenceRelation<int> TestEquivRelation2();


TEST_CASE("Tests EquivalenceRelation::GetClass") {
    EquivalenceRelation<unsigned char>::EquivClass c1 {1, 2};
    EquivalenceRelation<unsigned char>::EquivClass c2 {5};
    std::vector<EquivalenceRelation<unsigned char>::EquivClass> classes {c1, c2};
    const EquivalenceRelation<unsigned char> relation(classes);
    CHECK(relation.GetClass(1) == c1);
    CHECK(relation.GetClass(2) == c1);
    CHECK(relation.GetClass(5) == c2);
}


TEST_CASE("Tests EquivalenceRelation::Exists and EquivalenceRelation::IsEquiv") {
    const EquivalenceRelation<unsigned char> relation = TestEquivRelation1();
    CHECK(relation.Exists(0));
    CHECK(relation.Exists(1));
    CHECK(!relation.Exists(2));
    CHECK(relation.Exists(3));
    CHECK(!relation.Exists(4));
    CHECK(!relation.Exists(5));
    CHECK(relation.Exists(6));
    CHECK(relation.Exists(7));
    CHECK(relation.Exists(8));
    CHECK(!relation.Exists(9));
    CHECK(relation.IsEquiv(0, 0));
    CHECK(!relation.IsEquiv(0, 1));
    CHECK(!relation.IsEquiv(0, 2));
    CHECK(!relation.IsEquiv(0, 3));
    CHECK(!relation.IsEquiv(0, 4));
    CHECK(!relation.IsEquiv(0, 5));
    CHECK(!relation.IsEquiv(0, 6));
    CHECK(!relation.IsEquiv(0, 7));
    CHECK(!relation.IsEquiv(0, 8));
    CHECK(!relation.IsEquiv(0, 9));
    CHECK(!relation.IsEquiv(1, 0));
    CHECK(relation.IsEquiv(1, 1));
    CHECK(!relation.IsEquiv(1, 2));
    CHECK(relation.IsEquiv(1, 3));
    CHECK(!relation.IsEquiv(1, 4));
    CHECK(!relation.IsEquiv(1, 5));
    CHECK(!relation.IsEquiv(1, 6));
    CHECK(!relation.IsEquiv(1, 7));
    CHECK(!relation.IsEquiv(1, 8));
    CHECK(!relation.IsEquiv(1, 9));
    CHECK(!relation.IsEquiv(2, 0));
    CHECK(!relation.IsEquiv(2, 1));
    CHECK(!relation.IsEquiv(2, 2));
    CHECK(!relation.IsEquiv(2, 3));
    CHECK(!relation.IsEquiv(2, 4));
    CHECK(!relation.IsEquiv(2, 5));
    CHECK(!relation.IsEquiv(2, 6));
    CHECK(!relation.IsEquiv(2, 7));
    CHECK(!relation.IsEquiv(2, 8));
    CHECK(!relation.IsEquiv(2, 9));
    CHECK(!relation.IsEquiv(3, 0));
    CHECK(relation.IsEquiv(3, 1));
    CHECK(!relation.IsEquiv(3, 2));
    CHECK(relation.IsEquiv(3, 3));
    CHECK(!relation.IsEquiv(3, 4));
    CHECK(!relation.IsEquiv(3, 5));
    CHECK(!relation.IsEquiv(3, 6));
    CHECK(!relation.IsEquiv(3, 7));
    CHECK(!relation.IsEquiv(3, 8));
    CHECK(!relation.IsEquiv(3, 9));
    CHECK(!relation.IsEquiv(4, 0));
    CHECK(!relation.IsEquiv(4, 1));
    CHECK(!relation.IsEquiv(4, 2));
    CHECK(!relation.IsEquiv(4, 3));
    CHECK(!relation.IsEquiv(4, 4));
    CHECK(!relation.IsEquiv(4, 5));
    CHECK(!relation.IsEquiv(4, 6));
    CHECK(!relation.IsEquiv(4, 7));
    CHECK(!relation.IsEquiv(4, 8));
    CHECK(!relation.IsEquiv(4, 9));
    CHECK(!relation.IsEquiv(5, 0));
    CHECK(!relation.IsEquiv(5, 1));
    CHECK(!relation.IsEquiv(5, 2));
    CHECK(!relation.IsEquiv(5, 3));
    CHECK(!relation.IsEquiv(5, 4));
    CHECK(!relation.IsEquiv(5, 5));
    CHECK(!relation.IsEquiv(5, 6));
    CHECK(!relation.IsEquiv(5, 7));
    CHECK(!relation.IsEquiv(5, 8));
    CHECK(!relation.IsEquiv(5, 9));
    CHECK(!relation.IsEquiv(6, 0));
    CHECK(!relation.IsEquiv(6, 1));
    CHECK(!relation.IsEquiv(6, 2));
    CHECK(!relation.IsEquiv(6, 3));
    CHECK(!relation.IsEquiv(6, 4));
    CHECK(!relation.IsEquiv(6, 5));
    CHECK(relation.IsEquiv(6, 6));
    CHECK(relation.IsEquiv(6, 7));
    CHECK(relation.IsEquiv(6, 8));
    CHECK(!relation.IsEquiv(6, 9));
    CHECK(!relation.IsEquiv(7, 0));
    CHECK(!relation.IsEquiv(7, 1));
    CHECK(!relation.IsEquiv(7, 2));
    CHECK(!relation.IsEquiv(7, 3));
    CHECK(!relation.IsEquiv(7, 4));
    CHECK(!relation.IsEquiv(7, 5));
    CHECK(relation.IsEquiv(7, 6));
    CHECK(relation.IsEquiv(7, 7));
    CHECK(relation.IsEquiv(7, 8));
    CHECK(!relation.IsEquiv(7, 9));
    CHECK(!relation.IsEquiv(8, 0));
    CHECK(!relation.IsEquiv(8, 1));
    CHECK(!relation.IsEquiv(8, 2));
    CHECK(!relation.IsEquiv(8, 3));
    CHECK(!relation.IsEquiv(8, 4));
    CHECK(!relation.IsEquiv(8, 5));
    CHECK(relation.IsEquiv(8, 6));
    CHECK(relation.IsEquiv(8, 7));
    CHECK(relation.IsEquiv(8, 8));
    CHECK(!relation.IsEquiv(8, 9));
    CHECK(!relation.IsEquiv(9, 0));
    CHECK(!relation.IsEquiv(9, 1));
    CHECK(!relation.IsEquiv(9, 2));
    CHECK(!relation.IsEquiv(9, 3));
    CHECK(!relation.IsEquiv(9, 4));
    CHECK(!relation.IsEquiv(9, 5));
    CHECK(!relation.IsEquiv(9, 6));
    CHECK(!relation.IsEquiv(9, 7));
    CHECK(!relation.IsEquiv(9, 8));
    CHECK(!relation.IsEquiv(9, 9));
}


TEST_CASE("Tests EquivalenceRelation::MergeClasses") {
    EquivalenceRelation<unsigned char> relation = TestEquivRelation1();
    CHECK(relation.IsEquiv(0, 0));
    CHECK(!relation.IsEquiv(0, 1));
    CHECK(!relation.IsEquiv(0, 3));
    CHECK(!relation.IsEquiv(0, 6));
    CHECK(!relation.IsEquiv(0, 7));
    CHECK(!relation.IsEquiv(0, 8));
    CHECK(relation.IsEquiv(1, 1));
    CHECK(relation.IsEquiv(1, 3));
    CHECK(!relation.IsEquiv(1, 6));
    CHECK(!relation.IsEquiv(1, 7));
    CHECK(!relation.IsEquiv(1, 8));
    CHECK(relation.IsEquiv(3, 3));
    CHECK(!relation.IsEquiv(3, 6));
    CHECK(!relation.IsEquiv(3, 7));
    CHECK(!relation.IsEquiv(3, 8));
    CHECK(relation.IsEquiv(6, 6));
    CHECK(relation.IsEquiv(6, 7));
    CHECK(relation.IsEquiv(6, 8));
    CHECK(relation.IsEquiv(7, 7));
    CHECK(relation.IsEquiv(7, 8));
    CHECK(relation.IsEquiv(8, 8));
    relation.MergeClasses(relation.GetClass(0), relation.GetClass(6));
    CHECK(relation.IsEquiv(0, 0));
    CHECK(!relation.IsEquiv(0, 1));
    CHECK(!relation.IsEquiv(0, 3));
    CHECK(relation.IsEquiv(0, 6));
    CHECK(relation.IsEquiv(0, 7));
    CHECK(relation.IsEquiv(0, 8));
    CHECK(relation.IsEquiv(1, 1));
    CHECK(relation.IsEquiv(1, 3));
    CHECK(!relation.IsEquiv(1, 6));
    CHECK(!relation.IsEquiv(1, 7));
    CHECK(!relation.IsEquiv(1, 8));
    CHECK(relation.IsEquiv(3, 3));
    CHECK(!relation.IsEquiv(3, 6));
    CHECK(!relation.IsEquiv(3, 7));
    CHECK(!relation.IsEquiv(3, 8));
    CHECK(relation.IsEquiv(6, 6));
    CHECK(relation.IsEquiv(6, 7));
    CHECK(relation.IsEquiv(6, 8));
    CHECK(relation.IsEquiv(7, 7));
    CHECK(relation.IsEquiv(7, 8));
    CHECK(relation.IsEquiv(8, 8));
    relation.MergeClasses(relation.GetClass(0), relation.GetClass(7));
    CHECK(relation.IsEquiv(0, 0));
    CHECK(!relation.IsEquiv(0, 1));
    CHECK(!relation.IsEquiv(0, 3));
    CHECK(relation.IsEquiv(0, 6));
    CHECK(relation.IsEquiv(0, 7));
    CHECK(relation.IsEquiv(0, 8));
    CHECK(relation.IsEquiv(1, 1));
    CHECK(relation.IsEquiv(1, 3));
    CHECK(!relation.IsEquiv(1, 6));
    CHECK(!relation.IsEquiv(1, 7));
    CHECK(!relation.IsEquiv(1, 8));
    CHECK(relation.IsEquiv(3, 3));
    CHECK(!relation.IsEquiv(3, 6));
    CHECK(!relation.IsEquiv(3, 7));
    CHECK(!relation.IsEquiv(3, 8));
    CHECK(relation.IsEquiv(6, 6));
    CHECK(relation.IsEquiv(6, 7));
    CHECK(relation.IsEquiv(6, 8));
    CHECK(relation.IsEquiv(7, 7));
    CHECK(relation.IsEquiv(7, 8));
    CHECK(relation.IsEquiv(8, 8));
    relation.MergeClasses(relation.GetClass(6), relation.GetClass(1));
    CHECK(relation.IsEquiv(0, 0));
    CHECK(relation.IsEquiv(0, 1));
    CHECK(relation.IsEquiv(0, 3));
    CHECK(relation.IsEquiv(0, 6));
    CHECK(relation.IsEquiv(0, 7));
    CHECK(relation.IsEquiv(0, 8));
    CHECK(relation.IsEquiv(1, 1));
    CHECK(relation.IsEquiv(1, 3));
    CHECK(relation.IsEquiv(1, 6));
    CHECK(relation.IsEquiv(1, 7));
    CHECK(relation.IsEquiv(1, 8));
    CHECK(relation.IsEquiv(3, 3));
    CHECK(relation.IsEquiv(3, 6));
    CHECK(relation.IsEquiv(3, 7));
    CHECK(relation.IsEquiv(3, 8));
    CHECK(relation.IsEquiv(6, 6));
    CHECK(relation.IsEquiv(6, 7));
    CHECK(relation.IsEquiv(6, 8));
    CHECK(relation.IsEquiv(7, 7));
    CHECK(relation.IsEquiv(7, 8));
    CHECK(relation.IsEquiv(8, 8));
}


TEST_CASE("Tests EquivalenceRelation::AddConnection") {
    EquivalenceRelation<unsigned char> relation = TestEquivRelation1();
    CHECK(relation.IsEquiv(0, 0));
    CHECK(!relation.IsEquiv(0, 1));
    CHECK(!relation.IsEquiv(0, 3));
    CHECK(!relation.IsEquiv(0, 6));
    CHECK(!relation.IsEquiv(0, 7));
    CHECK(!relation.IsEquiv(0, 8));
    CHECK(relation.IsEquiv(1, 1));
    CHECK(relation.IsEquiv(1, 3));
    CHECK(!relation.IsEquiv(1, 6));
    CHECK(!relation.IsEquiv(1, 7));
    CHECK(!relation.IsEquiv(1, 8));
    CHECK(relation.IsEquiv(3, 3));
    CHECK(!relation.IsEquiv(3, 6));
    CHECK(!relation.IsEquiv(3, 7));
    CHECK(!relation.IsEquiv(3, 8));
    CHECK(relation.IsEquiv(6, 6));
    CHECK(relation.IsEquiv(6, 7));
    CHECK(relation.IsEquiv(6, 8));
    CHECK(relation.IsEquiv(7, 7));
    CHECK(relation.IsEquiv(7, 8));
    CHECK(relation.IsEquiv(8, 8));
    relation.AddConnection(1, 3);
    CHECK(relation.IsEquiv(0, 0));
    CHECK(!relation.IsEquiv(0, 1));
    CHECK(!relation.IsEquiv(0, 3));
    CHECK(!relation.IsEquiv(0, 6));
    CHECK(!relation.IsEquiv(0, 7));
    CHECK(!relation.IsEquiv(0, 8));
    CHECK(relation.IsEquiv(1, 1));
    CHECK(relation.IsEquiv(1, 3));
    CHECK(!relation.IsEquiv(1, 6));
    CHECK(!relation.IsEquiv(1, 7));
    CHECK(!relation.IsEquiv(1, 8));
    CHECK(relation.IsEquiv(3, 3));
    CHECK(!relation.IsEquiv(3, 6));
    CHECK(!relation.IsEquiv(3, 7));
    CHECK(!relation.IsEquiv(3, 8));
    CHECK(relation.IsEquiv(6, 6));
    CHECK(relation.IsEquiv(6, 7));
    CHECK(relation.IsEquiv(6, 8));
    CHECK(relation.IsEquiv(7, 7));
    CHECK(relation.IsEquiv(7, 8));
    CHECK(relation.IsEquiv(8, 8));
    relation.AddConnection(0, 2);
    CHECK(relation.IsEquiv(0, 0));
    CHECK(!relation.IsEquiv(0, 1));
    CHECK(!relation.IsEquiv(0, 3));
    CHECK(!relation.IsEquiv(0, 6));
    CHECK(!relation.IsEquiv(0, 7));
    CHECK(!relation.IsEquiv(0, 8));
    CHECK(relation.IsEquiv(1, 1));
    CHECK(relation.IsEquiv(1, 3));
    CHECK(!relation.IsEquiv(1, 6));
    CHECK(!relation.IsEquiv(1, 7));
    CHECK(!relation.IsEquiv(1, 8));
    CHECK(relation.IsEquiv(3, 3));
    CHECK(!relation.IsEquiv(3, 6));
    CHECK(!relation.IsEquiv(3, 7));
    CHECK(!relation.IsEquiv(3, 8));
    CHECK(relation.IsEquiv(6, 6));
    CHECK(relation.IsEquiv(6, 7));
    CHECK(relation.IsEquiv(6, 8));
    CHECK(relation.IsEquiv(7, 7));
    CHECK(relation.IsEquiv(7, 8));
    CHECK(relation.IsEquiv(8, 8));
    CHECK(relation.IsEquiv(0, 2));
    CHECK(!relation.IsEquiv(1, 2));
    CHECK(relation.IsEquiv(2, 2));
    CHECK(!relation.IsEquiv(3, 2));
    CHECK(!relation.IsEquiv(6, 2));
    CHECK(!relation.IsEquiv(7, 2));
    CHECK(!relation.IsEquiv(8, 2));
    relation.AddConnection(2, 3);
    CHECK(relation.IsEquiv(0, 0));
    CHECK(relation.IsEquiv(0, 1));
    CHECK(relation.IsEquiv(0, 3));
    CHECK(!relation.IsEquiv(0, 6));
    CHECK(!relation.IsEquiv(0, 7));
    CHECK(!relation.IsEquiv(0, 8));
    CHECK(relation.IsEquiv(1, 1));
    CHECK(relation.IsEquiv(1, 3));
    CHECK(!relation.IsEquiv(1, 6));
    CHECK(!relation.IsEquiv(1, 7));
    CHECK(!relation.IsEquiv(1, 8));
    CHECK(relation.IsEquiv(3, 3));
    CHECK(!relation.IsEquiv(3, 6));
    CHECK(!relation.IsEquiv(3, 7));
    CHECK(!relation.IsEquiv(3, 8));
    CHECK(relation.IsEquiv(6, 6));
    CHECK(relation.IsEquiv(6, 7));
    CHECK(relation.IsEquiv(6, 8));
    CHECK(relation.IsEquiv(7, 7));
    CHECK(relation.IsEquiv(7, 8));
    CHECK(relation.IsEquiv(8, 8));
    CHECK(relation.IsEquiv(0, 2));
    CHECK(relation.IsEquiv(1, 2));
    CHECK(relation.IsEquiv(2, 2));
    CHECK(relation.IsEquiv(3, 2));
    CHECK(!relation.IsEquiv(6, 2));
    CHECK(!relation.IsEquiv(7, 2));
    CHECK(!relation.IsEquiv(8, 2));
}


TEST_CASE("Tests EquivalenceRelation::Domain") {
    const tollk::EquivalenceRelation<int> relation = TestEquivRelation2();
    std::vector<int> domain = relation.Domain();
    std::sort(domain.begin(), domain.end());
    CHECK(domain.size() == 4);
    CHECK(domain[0] == 0);
    CHECK(domain[1] == 1);
    CHECK(domain[2] == 3);
    CHECK(domain[3] == 4);
}


TEST_CASE("Tests EquivalenceRelation::Classes") {
    const tollk::EquivalenceRelation<int> relation = TestEquivRelation2();
    const std::vector<tollk::EquivalenceRelation<int>::EquivClass> classes = relation.Classes();
    CHECK(classes.size() == 2);
    tollk::EquivalenceRelation<int>::EquivClass c1 = classes[0];
    tollk::EquivalenceRelation<int>::EquivClass c2 = classes[1];
    REQUIRE((c1.size() == 1 || c2.size() == 2));
    if (c1.size() != 1)
        std::swap(c1, c2);
    CHECK(c1.size() == 1);
    CHECK(c2.size() == 3);
    CHECK(c1.find(0) != c1.end());
    CHECK(c2.find(1) != c2.end());
    CHECK(c2.find(3) != c2.end());
    CHECK(c2.find(4) != c2.end());
}


TEST_CASE("Tests EquivalenceRelation::operator==") {
    const tollk::EquivalenceRelation<int> relation = TestEquivRelation2();
    CHECK(relation == relation);
    CHECK(relation == TestEquivRelation2());
    tollk::EquivalenceRelation<int> relation2;
    relation2.AddConnection(3, 4);
    relation2.AddConnection(1, 3);
    relation2.AddConnection(0, 0);
    CHECK(relation == relation2);
}


TEST_CASE("Tests EquivalenceRelation::SplitClass") {
    const EquivalenceRelation<int>::EquivClass c1 {0, 1};
    const EquivalenceRelation<int>::EquivClass c2 {2, 3, 4};
    const EquivalenceRelation<int>::EquivClass c3 {5, 6};
    const EquivalenceRelation<int> relation(std::vector<EquivalenceRelation<int>::EquivClass> {c1, c2, c3});
    const EquivalenceRelation<int>::EquivClass split {2, 3};
    EquivalenceRelation<int> relation2 = relation;
    relation2.SplitClass(0, split);
    CHECK(relation == relation2);
    relation2.SplitClass(1, split);
    CHECK(relation2.Classes().size() == 4);
    CHECK(relation2.IsEquiv(0, 1));
    CHECK(relation2.IsEquiv(5, 6));
    CHECK(relation2.IsEquiv(2, 3));
    CHECK(!relation2.IsEquiv(2, 4));
    CHECK(!relation2.IsEquiv(3, 4));
}


TEST_CASE("Tests EquivalenceRelation::Intersection") {
    //TODO
}

