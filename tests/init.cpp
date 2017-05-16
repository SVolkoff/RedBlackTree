#include <tree.h>
#include <catch.hpp>

SCENARIO ("init", "[init]")
{
  Tree<int> test;
  REQUIRE(test.root_() == nullptr);
}
SCENARIO("insert", "[init]")
{
  Tree<int> test;
  test.insertNode(5);
  REQUIRE(test.find_node(5)->data == 5);
}
SCENARIO("all", "[all]")
{
 Tree<int> test;
	test.insertNode(4);
	test.insertNode(5);
	test.insertNode(3);
	test.insertNode(2);
	test.insertNode(7);
	test.insertNode(10);
	test.insertNode(11);
	test.insertNode(6);
	test.insertNode(1);
	test.insertNode(12);
	test.insertNode(8);
	test.insertNode(9);
  REQUIRE(test.find_node(1)->color ==1);
  REQUIRE(test.find_node(2)->color ==0);
  REQUIRE(test.find_node(3)->color ==1);
  REQUIRE(test.find_node(4)->color ==1);
  REQUIRE(test.find_node(5)->color ==0);
  REQUIRE(test.find_node(6)->color ==1);
  REQUIRE(test.find_node(7)->color ==0);
  REQUIRE(test.find_node(8)->color ==1);
  REQUIRE(test.find_node(9)->color ==0);
  REQUIRE(test.find_node(10)->color ==1);
  REQUIRE(test.find_node(11)->color ==1);
  REQUIRE(test.find_node(12)->color ==0);
}
