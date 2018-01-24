# [LeetCode](https://leetcode.com/problemset/algorithms/) / [Hackerrank](https://www.hackerrank.com/domains/algorithms) ![Language](https://img.shields.io/badge/language-C++-orange.svg) [![License](https://img.shields.io/badge/license-MIT-blue.svg)](./LICENSE.md) [![SayThanks](https://img.shields.io/badge/say-thanks-ff69b4.svg)](https://saythanks.io/to/boraikizoglu)


## 0001-sortingAlgorithmsRuntimeComparison.cpp
![Runtime Comparison Result](https://github.com/boraikizoglu/Algorithms/blob/master/Images/runtimeComparisonResult.png)


## 0002-findTheDuplicateNumber.cpp

<div><p>
Given an array <i>nums</i> containing <i>n</i> + 1 integers where each integer is between 1 and <i>n</i> (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
</p>

<p>
<b>Note:</b><br>
</p><ol>
<li>You <b>must not</b> modify the array (assume the array is read only).</li>
<li>You must use only constant, <i>O</i>(1) extra space.</li>
<li>Your runtime complexity should be less than <code>O(n<sup>2</sup>)</code>.</li>
<li>There is only one duplicate number in the array, but it could be repeated more than once.</li>
</ol>
<p></p>

</div>

## 0003-equilibriumIndex.cpp

<div id="brinza-task-description">
<p>A zero-indexed array A consisting of N integers is given. An <i>equilibrium index</i> of this array is any integer P such that 0 ≤ P &lt; N and the sum of elements of lower indices is equal to the sum of elements of higher indices, i.e. <br>
</p>
<blockquote><p>A[0] + A[1] + ... + A[P−1] = A[P+1] + ... + A[N−2] + A[N−1].<br>
</p></blockquote>
<p>Sum of zero elements is assumed to be equal to 0. This can happen if P = 0 or if P = N−1.</p>
<p>For example, consider the following array A consisting of N = 8 elements:</p>
<tt style="white-space:pre-wrap">  A[0] = -1
  A[1] =  3
  A[2] = -4
  A[3] =  5
  A[4] =  1
  A[5] = -6
  A[6] =  2
  A[7] =  1</tt>
<p>P = 1 is an equilibrium index of this array, because:</p>
<blockquote><ul style="margin: 10px;padding: 0px;"><li>A[0] = −1 = A[2] + A[3] + A[4] + A[5] + A[6] + A[7]</li>
</ul>
</blockquote><p>P = 3 is an equilibrium index of this array, because:</p>
<blockquote><ul style="margin: 10px;padding: 0px;"><li>A[0] + A[1] + A[2] = −2 = A[4] + A[5] + A[6] + A[7]</li>
</ul>
</blockquote><p>P = 7 is also an equilibrium index, because:</p>
<blockquote><ul style="margin: 10px;padding: 0px;"><li>A[0] + A[1] + A[2] + A[3] + A[4] + A[5] + A[6] = 0</li>
</ul>
</blockquote><p>and there are no elements with indices greater than 7.</p>
<p>P = 8 is not an equilibrium index, because it does not fulfill the condition 0 ≤ P &lt; N.</p>
<p>Write a function:</p>
<blockquote><p style="font-family: monospace; font-size: 9pt; display: block; white-space: pre-wrap"><tt>class Solution { public int solution(int[] A); }</tt></p></blockquote>
<p>that, given a zero-indexed array A consisting of N integers, returns any of its equilibrium indices. The function should return −1 if no equilibrium index exists.</p>
<p>For example, given array A shown above, the function may return 1, 3 or 7, as explained above.</p>
<p>Assume that:</p>
<blockquote><ul style="margin: 10px;padding: 0px;"><li>N is an integer within the range [<span class="number">0</span>..<span class="number">100,000</span>];</li>
<li>each element of array A is an integer within the range [<span class="number">−2,147,483,648</span>..<span class="number">2,147,483,647</span>].</li>
</ul>
</blockquote><p>Complexity:</p>
<blockquote><ul style="margin: 10px;padding: 0px;"><li>expected worst-case time complexity is O(N);</li>
<li>expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).</li>
</ul>
</blockquote></div>

## 0004-singleNumber.cpp

<div class="question-description"><div><p>Given an array of integers, every element appears <i>twice</i> except for one. Find that single one.</p>

<p>
<b>Note:</b><br>
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
</p></div></div>

## 0005-Pow(x, n).cpp

<div><p>Implement <a href="http://www.cplusplus.com/reference/valarray/pow/" target="_blank">pow(<i>x</i>, <i>n</i>)</a>.
</p>

<br>

<p><b>Example 1:</b>
</p><pre><b>Input:</b> 2.00000, 10
<b>Output:</b> 1024.00000
</pre>
<p></p>

<p><b>Example 2:</b>
</p><pre><b>Input:</b> 2.10000, 3
<b>Output:</b> 9.26100
</pre>
<p></p></div>
