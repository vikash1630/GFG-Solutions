<h2><a href="https://www.geeksforgeeks.org/problems/unique-paths-in-a-grid--170647/1?utm_source=chatgpt.com">Unique Paths in a Grid</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18.6667px;">Given a grid <strong>grid[][]</strong> of size <strong>n</strong> × <strong>m</strong> containing values 0 and 1 having the following meanings:</span></p>
<ul>
<li><span style="font-size: 18.6667px;">0 represents an open cell through which movement is allowed.</span></li>
<li><span style="font-size: 18.6667px;">1 represents a blocked cell that cannot be traversed.</span></li>
</ul>
<p><span style="font-size: 14pt;">Starting from the top-left cell (0, 0), find the total number of distinct paths to reach the bottom-right cell (n - 1, m - 1). From any cell, movement is allowed only in the right and down directions, and a path is valid only if it passes through open cells.</span></p>
<p><span style="font-size: 14pt;"><strong>Note:</strong> It is guaranteed that the answer fits within a 32-bit integer.</span></p>
<p><span style="font-size: 14pt;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong style="font-size: 14pt;">Input: </strong><span style="font-size: 14pt;">grid[][] = {{0, 0, 0},{0, 1, 0},{0, 0, 0}}
</span><strong style="font-size: 14pt;">Output: </strong><span style="font-size: 14pt;">2
</span><strong style="font-size: 14pt;">Explanation: </strong><span style="font-size: 18.6667px;">There are two distinct paths from (0, 0) to (2, 2) while avoiding the blocked cell.</span><span style="font-size: 14pt;"><br><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/929509/Web/Other/blobid0_1781081641.png" height="100"> </span></span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>grid[][] = {{1, 0, 1}}
<strong>Output: </strong>0
<strong>Explanation: </strong>There is no possible path to reach the end.
</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>1 ≤ n*m ≤ 10<sup>6</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Uber</code>&nbsp;<code>Amazon</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Matrix</code>&nbsp;