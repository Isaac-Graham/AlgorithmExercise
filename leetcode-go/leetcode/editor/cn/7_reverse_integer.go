package main

import (
	"fmt"
	"math"
	"strconv"
)

//////给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
//////
////// 如果反转后整数超过 32 位的有符号整数的范围 [−2³¹, 231 − 1] ，就返回 0。
//////假设环境不允许存储 64 位整数（有符号或无符号）。
//////
//////
//////
////// 示例 1：
//////
//////
//////输入：x = 123
//////输出：321
//////
//////
////// 示例 2：
//////
//////
//////输入：x = -123
//////输出：-321
//////
//////
////// 示例 3：
//////
//////
//////输入：x = 120
//////输出：21
//////
//////
////// 示例 4：
//////
//////
//////输入：x = 0
//////输出：0
//////
//////
//////
//////
////// 提示：
//////
//////
////// -2³¹ <= x <= 2³¹ - 1
//////
////// Related Topics 数学 👍 3362 👎 0
////
//

//leetcode submit region begin(Prohibit modification and deletion)
func reverse(x int) int {
	positive := x
	signature := ""
	if x < 0 {
		positive = -1 * positive
		signature = "-"
	} else if x == 0 {
		return x
	}

	res := ""

	s := fmt.Sprintf("%d", positive)

	for _, r := range s {
		res = fmt.Sprintf("%c%s", r, res)
	}

	resInt, _ := strconv.Atoi(fmt.Sprintf("%s%s", signature, res))

	if resInt > math.MaxInt32 || resInt< math.MinInt32 {
		return 0
	}
	return resInt
}

//leetcode submit region end(Prohibit modification and deletion)

func main() {
	//fmt.Println(reverse(1234567))
	fmt.Println(reverse(-1234))
}
