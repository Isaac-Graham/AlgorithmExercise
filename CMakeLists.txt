cmake_minimum_required(VERSION 3.10)
project(Leetcode)

set(CMAKE_CXX_STANDARD 14)

#add_executable(Q ByteDance/2020InternCodingPart/Coupon.cpp)
#add_executable(KickStart KickStart/2020CRound/Perfect_Subarray.cpp)
add_executable(leetcode leetcode/editor/cn/Utils.h
        leetcode/editor/cn/[917]reverse-only-letters.cpp)
add_executable(main main.cpp)
#add_executable(alibaba Alibaba/2020Fall/OnlineCoding/20200724-Q1.cpp )
add_executable(tencent Tencent/技术架构/二面/question3.cpp)
#add_executable(wangyi wangyi/Q4.cpp)
add_executable(shopee Shopee/question3.cpp)
add_executable(huawei Huawei/interview/question2.cpp)
add_executable(nvidia Nvidia/20200907/question2.cpp)
add_executable(microsoft Microsoft/question2.cpp)