#include <tree.h>
#include <catch.hpp>


SCENARIO("insert")
{
	Tree<int> test;
	test.insertNode(1);
	REQUIRE(test.find_node(1)!=nullptr);
}
SCENARIO("del")
{
	Tree<int> test;
	test.insertNode(1);
	test.deleteVal(1);
	REQUIRE(test.find_node(1)==nullptr);
}
SCENARIO("del1")
{
	Tree<int> tree;
	tree.insertNode(8);
	tree.deleteNode(tree.find_node(8));
	REQUIRE((tree.root_()) == 0);
}
SCENARIO("del2")
{
	Tree<int> tree1 ;
	tree1.insertNode(7);
	tree1.insertNode(5);
	tree1.insertNode(4);
	tree1.deleteVal(7);
	
	Tree<int> tree11;
	tree11.insertNode(5);
	tree11.insertNode(4);
	REQUIRE(tree1 == tree11);
}
SCENARIO("del3")
{
	Tree<int>  tree2;
	tree2.insertNode(8);
	tree2.insertNode(3);
	tree2.insertNode(2);
	tree2.insertNode(10);
	tree2.insertNode(9);
	tree2.insertNode(14);
	tree2.insertNode(11);
	tree2.insertNode(12);
	tree2.deleteNode(tree2.find_node(3));

	Tree<int>  tree22 ;
	tree22.insertNode(9);
	tree22.insertNode(8);
	tree22.insertNode(11);
	tree22.insertNode(2);
	tree22.insertNode(10);
	tree22.insertNode(14);
	tree22.insertNode(12);
	REQUIRE(tree2 == tree22);
}
SCENARIO("del4")
{
	Tree<int>  tree3;
	 tree3.insertNode(8);
	 tree3.insertNode(4);
	 tree3.insertNode(3);
	 tree3.insertNode(10);
	 tree3.insertNode(9);
	 tree3.insertNode(16);
	 tree3.insertNode(11);
	 tree3.insertNode(12);
	tree3.deleteNode(tree3.find_node(3));
	
	Tree<int>  tree33;
	tree33.insertNode(9);
	tree33.insertNode(4);
	tree33.insertNode(11);
	tree33.insertNode(10);
	tree33.insertNode(16);
	tree33.insertNode(12);
	tree33.insertNode(8);
	
	REQUIRE(tree3 == tree33);
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
