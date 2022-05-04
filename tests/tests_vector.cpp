//
// Created by bartem1us on 3/28/21.
//
#include <vector.h>
#include <Iterator.h>
#include <gtest/gtest.h>
TEST(Vector,Iterator)
{
  vector<int> vec(5,5);// check constructor
      vec[1]=1;
  vec[2]=2;
  vec[3]=3; //check []
  auto it = vec.begin() ;//check begin + iterator const
  EXPECT_EQ(*it,5);
  EXPECT_EQ(vec[2],2);
  ++it;
  EXPECT_EQ(*it,1);
  it++;
  EXPECT_EQ(*it,2);
  --it;
  EXPECT_EQ(*it,1);
  it--;
  EXPECT_EQ(*it,5);
  auto it2=it;
  EXPECT_EQ(*it,5);
  EXPECT_EQ(it2==it,true);
  EXPECT_EQ(it2!=it,false);

}
TEST(vector,base)
{
  vector<int> vec2(4,4);
  vector<int> vec3(vec2);

  size_t size2 = vec2.size();
  EXPECT_EQ(size2,4);
  EXPECT_EQ(vec2.empty(),false);
  vec2.push_back(3);
  int rv= vec2[4];
  EXPECT_EQ(rv,3);
EXPECT_EQ(vec2.front(),4);
EXPECT_EQ(vec2.back(),3);
vec2.swap(vec3);
EXPECT_EQ(vec3.back(),3);

}

TEST(vector,clear) {
  vector<int> vec3 ;
  vec3.push_back(3);
  vec3.push_back(4);
  EXPECT_EQ(vec3.size(), 2);

}