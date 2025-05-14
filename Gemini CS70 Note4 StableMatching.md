#review 

>Rogue cuple: the root of unstablity
>Candidates and Jobs: There is difference, there is solvablity
>Basic Lemma: well-order principle: For a $\mathbf{Z}$ Set, a minimum value is determined to exist
>Best matching and worst matching coexist: best for employers, worst for candidates. Those who receive and check applications, and then keep choosing the best, are greatly benefited from this system.

>The proofs show their importance: We need to ==prove the algorithm to be effective and it will finally halt after finding the exact solutions==
>We can balance some relationships by improving its underlying algorithm like this: ==Students selecting offers is better for students than requiring students to keep sending offers to those institutions for internship==.

好的，同学们！欢迎回到 EECS 70 的课堂。今天我们要探讨一个非常有趣且重要的离散数学应用问题——稳定匹配问题 (Stable Matching Problem)。这个问题不仅理论优美，而且在现实世界中有许多实际应用，甚至催生了诺贝尔经济学奖的诞生。所以，请大家打起精神，跟着我一起深入理解它。

### 引入与动机

想象一下，你负责为一个大型实习项目牵线搭桥，一边是 $n$ 个公司（我们称之为“工作”），另一边是 $n$ 个应聘学生（我们称之为“候选人”）。每个公司对应聘者都有一个偏好列表，从最喜欢到最不喜欢；同样，每个应聘者对公司也有一个偏好列表。

你的任务是找到一个“好”的匹配方案，把每个工作分配给一个候选人，并且每个候选人被分配到一个工作。一个直接的问题是：什么样的匹配才算是“好”的呢？仅仅是完成一对一匹配就行吗？

考虑一下，如果你给出了一个匹配方案，但发现某个公司 J 对一个未被它匹配到的候选人 C* 非常满意，比它当前匹配到的候选人要满意得多。巧的是，候选人 C* 也对公司 J 非常满意，比她当前匹配到的公司要满意得多。这种情况下会发生什么？很自然地，<font color="#ffff00">公司 J 和候选人 C* 就有“私奔”的冲动！他们可能会打破你安排的匹配</font>，自己偷偷地组合在一起。这样一来，你辛苦建立的匹配就会不稳定，可能导致其他公司和候选人也跟着变动，整个系统就乱套了。

所以，“好”的一个重要标准是**稳定性 (Stability)**。我们不希望出现这种情况：一个工作 J 和一个候选人 C*，他们当前都没有匹配到对方，但 J 喜欢 C* 胜过自己当前的匹配对象，同时 C* 也喜欢 J 胜过自己当前的匹配对象。如果存在这样一对 J 和 C*，我们就称他们为**潜在的“流氓伴侣” (rogue couple)**，而当前的匹配就是**不稳定 (unstable)** 的。我们的目标是找到一个**稳定 (stable)** 的匹配，也就是说，没有任何一对未匹配的 Job 和 Candidate 构成流氓伴侣。

听起来很有挑战性，是吗？毕竟有那么多的偏好列表交织在一起。有没有一个系统性的方法能找到这样的稳定匹配呢？这就是我们今天要学习的重点。这个领域最著名的算法叫做 **“求婚-拒绝算法” (Propose-and-Reject Algorithm)**，也称为 **Gale-Shapley 算法**。它不仅简单，而且非常高效实用。

### 必要知识回顾

今天的讲解不需要太多复杂的数学前置知识，主要是理解集合、配对（matching）的概念以及基本的逻辑推理（特别是证明方法）。

*   **匹配 (Matching):** 在我们的场景中，一个匹配就是把 $n$ 个工作和 $n$ 个候选人一一配对，形成 $n$ 对 (Job, Candidate)。每一对包含一个工作和一个候选人，每个工作和每个候选人都只能出现在一对中一次。
*   **偏好列表 (Preference List):** 每个工作和每个候选人都有一个对另一方所有个体的排序列表。这个排序决定了他们的偏好程度。

我们需要特别关注的是，这里涉及到**两种不同类型的个体**（Jobs 和 Candidates），匹配只能发生在不同类型之间。这一点在我们后面理解稳定匹配的存在性时会非常关键。

### 直观解释与感性认识

想象一下一个相亲大会。有 $n$ 位男士和 $n$ 位女士。每位男士心里都有一个按喜欢程度排名的女士名单，每位女士心里也有一个按喜欢程度排名的男士名单。我们要做的就是撮合这 $n$ 对，让大家尽可能满意，至少要达到“稳定”的状态，即不会出现“挖墙脚”的情况。

“求婚-拒绝算法”的直观思想是：让主动方（比如男士）积极地向他们最喜欢的、还没有拒绝过他们的女士求婚。女士则在收到的所有求婚中，保留那个最好的，对其他的说“不”。被拒绝的男士就去追求他们名单上的下一个。这个过程不断迭代，直到所有男士都被接受（暂时或最终）。

为什么要让男士（或一方）来主动求婚呢？这个设定非常重要，它决定了最终匹配的一些关键特性，我们稍后会看到。

### 逐步形式化与精确定义

现在，让我们用更精确的语言来定义核心概念，这有助于我们进行严谨的分析和证明。

我们有 $n$ 个工作集合 $J = \{J_1, J_2, \dots, J_n\}$ 和 $n$ 个候选人集合 $C = \{C_1, C_2, \dots, C_n\}$。

*   **匹配 (Matching):** 是一个包含 $n$ 对 $(J_i, C_j)$ 的集合，其中每个工作 $J_i$ 和每个候选人 $C_j$ 都恰好在集合中出现一次。
*   **偏好 (Preference):** 对于每个 $J_i \in J$，有一个对 $C$ 中所有元素的排序列表 $P_i(J)$. 例如，$C_a$ 在 $C_b$ 前面表示 $J_i$ 偏好 $C_a$ 胜过 $C_b$。类似地，对于每个 $C_j \in C$，有一个对 $J$ 中所有元素的排序列表 $P_j(C)$。
*   **不稳定匹配 (Unstable Matching):** 一个匹配 $M$ 是不稳定的，如果存在一对 $(J, C^*)$ 不属于 $M$，但满足：
    1.  $J$ 偏好 $C^*$ 胜过它在 $M$ 中的伴侣 $C$ (i.e., $C^*$ 出现在 $C$ 前面的 $P_J(C)$ 列表里)。
    2.  $C^*$ 偏好 $J$ 胜过她在 $M$ 中的伴侣 $J^*$ (i.e., $J$ 出现在 $J^*$ 前面的 $P_{C^*}(J)$ 列表里)。
    我们称 $(J, C^*)$ 为一个**流氓伴侣 (rogue couple)**。
*   **稳定匹配 (Stable Matching):** 一个匹配是稳定的，当且仅当它不是不稳定的，也就是说，不存在任何流氓伴侣。

让我们回到 Note 中提供的例子：$n=3$ 的情况。
工作: Approximation Inc. (AInc), Basis Co. (BCo), Control Corp. (CCorp)
候选人: Anita (A), Bridget (B), Christine (C)

偏好列表：
AInc: A > B > C
BCo: B > A > C
CCorp: A > B > C

A: BCo > AInc > CCorp
B: AInc > BCo > CCorp
C: AInc > BCo > CCorp

考虑匹配 $$M_1 = \text{\{(AInc, C), (BCo, B), (CCorp, A)\}}$$这个匹配稳定吗？我们检查是否存在流氓伴侣。
流氓伴侣 $(J, C^*)$ 需要满足 $J$ 不与 $C^*$ 匹配，但 $J$ 喜欢 $C^*$ 胜过其当前伴侣，且 $C^*$ 喜欢 $J$ 胜过其当前伴侣。

在 $M_1$ 中：
*   AInc 匹配 C。AInc 喜欢 A 和 B 胜过 C。
*   BCo 匹配 B。BCo 喜欢 B（它是第一选择）。
*   CCorp 匹配 A。CCorp 喜欢 A（它是第一选择）。

*   A 匹配 CCorp。A 喜欢 BCo 和 AInc 胜过 CCorp。
*   B 匹配 BCo。B 喜欢 AInc 胜过 BCo。
*   C 匹配 AInc。C 喜欢 AInc（它是第一选择）。

现在看未匹配的对：
*   (AInc, A)? AInc 喜欢 A > C。A 喜欢 AInc > CCorp。是的！(AInc, A) 构成流氓伴侣。AInc 和 A 都更喜欢对方而不是他们当前的伴侣 (C 和 CCorp)。因此，$M_1$ 是不稳定的。
*   (AInc, B)? AInc 喜欢 B > C。B 喜欢 AInc > BCo。是的！(AInc, B) 也构成流氓伴侣。

Note 中给的 sanity check 例子是 $$\text{\{(Approximation Inc., Christine), (Basis Co., Bridget), (Control Corp., Anita)\}}$$. AInc 匹配 C, BCo 匹配 B, CCorp 匹配 A. 正是 $M_1$. Note 说 (AInc, Bridget) 是流氓伴侣。让我们再次检查：

*   AInc 匹配 C. AInc 喜欢 B 胜过 C. (第一条件满足)
*   Bridget 匹配 BCo. Bridget 喜欢 AInc 胜过 BCo. (第二条件满足)

是的，(AInc, Bridget) 是流氓伴侣。这个匹配确实是不稳定的。

Note 中提供的稳定匹配是 $$\text{\{(Basis Co., Anita), (Approximation Inc., Bridget), (Control Corp., Christine)\}}$$.
让我们检查一下：
*   BCo 匹配 A. BCo 的偏好: B > A > C. BCo 喜欢 B 胜过 A.
*   AInc 匹配 B. AInc 的偏好: A > B > C. AInc 喜欢 A 胜过 B.
*   CCorp 匹配 C. CCorp 的偏好: A > B > C. CCorp 喜欢 A 和 B 胜过 C.

*   A 匹配 BCo. A 的偏好: BCo > AInc > CCorp. A 喜欢 BCo.
*   B 匹配 AInc. B 的偏好: AInc > BCo > CCorp. B 喜欢 AInc.
*   C 匹配 CCorp. C 的偏好: AInc > BCo > CCorp. C 喜欢 AInc 和 BCo 胜过 CCorp.

潜在的流氓伴侣 $(J, C^*)$ (其中 $J$ 不与 $C^*$ 匹配):
*   (BCo, B)? BCo 喜欢 B > A. B 喜欢 AInc > BCo. B 不喜欢 BCo 胜过 AInc. 不是流氓伴侣。
*   (BCo, C)? BCo 喜欢 C < A. BCo 不喜欢 C 胜过其当前伴侣 A. 不是流氓伴侣。
*   (AInc, A)? AInc 喜欢 A > B. A 喜欢 BCo > AInc. A 不喜欢 AInc 胜过其当前伴侣 BCo. 不是流氓伴侣。
*   (AInc, C)? AInc 喜欢 C < B. AInc 不喜欢 C 胜过其当前伴侣 B. 不是流氓伴侣。
*   (CCorp, A)? CCorp 喜欢 A > C. A 喜欢 BCo > AInc > CCorp. A 不喜欢 CCorp 胜过其当前伴侣 BCo. 不是流氓伴侣。
*   (CCorp, B)? CCorp 喜欢 B > C. B 喜欢 AInc > BCo > CCorp. B 不喜欢 CCorp 胜过其当前伴侣 AInc. 不是流氓伴侣。

> [!summary] 
> 似乎没有流氓伴侣。这个匹配是稳定的。注意，尽管 CCorp 和 C 都匹配到了他们偏好列表上靠后的对象（对 CCorp 来说，C 在最后；对 C 来说，CCorp 在最后），但这并不影响稳定性，因为他们各自更喜欢的对象（A, B 对 CCorp；AInc, BCo 对 C）并没有同时喜欢 CCorp 或 C 胜过他们各自当前的伴侣。稳定性只关心是否存在双方都更满意的**未匹配**对。

**室友问题 (Roommates Problem)**

Note 中提到了室友问题作为一个对比。有 $2n$ 个人，他们要*两两配对*组成室友。每个人对其他 $2n-1$ 个人都有一个偏好列表。稳定性的定义类似：不存在两个人 A 和 B，他们不是室友，但 A 喜欢 B 胜过其当前室友，且 B 喜欢 A 胜过其当前室友。

室友问题的一个关键区别在于，个体之间是**同质的**，没有“工作”和“候选人”这样固定的两种类型。

Note 中给了一个 $n=2$ (即 4 个人 A, B, C, D) 的室友问题例子，它**不存在**稳定匹配：
A: B > C > D
B: C > A > D
C: A > B > D
D: 任何人都行（D 是最差选项）

任何一个匹配都包含两对室友。比如：
*   $\{(A,B), (C,D)\}$: A 喜欢 B (匹配成功)，B 喜欢 A (匹配成功)。C 喜欢 A>B>D，D 谁都行。检查流氓伴侣：(A, C)? A 喜欢 B > C. C 喜欢 A > B > D. C 喜欢 A 胜过 D. A 喜欢 B 胜过 C. 没有构成流氓伴侣。 (B, C)? B 喜欢 C > A > D. C 喜欢 A > B > D. B 喜欢 C 胜过 A (其当前伴侣). C 喜欢 B 胜过 D (其当前伴侣). **(B, C) 构成流氓伴侣!**
*   $\{(A,C), (B,D)\}$: A 喜欢 B > C > D. C 喜欢 A > B > D. A 和 C 匹配成功。B 喜欢 C > A > D, D 谁都行。检查流氓伴侣：(A, B)? A 喜欢 B > C. B 喜欢 C > A > D. B 喜欢 A 胜过 D. A 喜欢 B 胜过 C. 没有构成流氓伴侣。 (B, C)? B 喜欢 C > A > D. C 喜欢 A > B > D. B 喜欢 C 胜过 D. C 喜欢 A 胜过 B. 没有构成流氓伴侣。 
* Wait, check again. In $$\text{\{(A,C), (B,D)\}}$$: A is matched with C, B with D. Rogue couple (A,B)? A prefers B to C. B prefers C to A. No, not a rogue couple. Rogue couple (B,C)? B prefers C to D. C prefers A to B. No, not a rogue couple. Let me re-read the note's sanity check. Ah, "How about $$\text{{(B,C), (A,D)}}$$? This matching is unstable because now A and C are a rogue couple."
    *   Consider matching $\{(B,C), (A,D)\}$. B is matched with C, A is matched with D.
    *   Rogue couple (A,C)? A is matched with D. A prefers B > C > D. A prefers C to D. Yes. C is matched with B. C prefers A > B > D. C prefers A to B. Yes. **(A, C) 构成流氓伴侣！**

这个室友问题的例子表明，对于同质类型的个体，稳定匹配**可能不存在**。这强调了我们的工作/候选人问题中**类型不对称性**的重要性。<font color="#ffff00">任何声称稳定匹配总是存在于工作/候选人问题中的证明，都必须本质上利用这种不对称性</font>。

### 核心原理与推导过程

现在，我们来看看“求婚-拒绝算法”是如何运作的，以及它为什么能保证找到一个稳定匹配。

**算法步骤 (以工作为求婚方)：**

这个算法按天进行（或者说，按轮迭代）。
*   **每天早上：** 每个还没有被淘汰的工作，向它偏好列表上还没拒绝过它的、排名最高的候选人发送求婚。
*   **每天下午：** 每个候选人收集她收到的所有求婚。她选择其中她最喜欢的那个求婚，对该工作回复“待定”(on a string / in hand)。<font color="#ffff00">对其他所有求婚，她回复“拒绝”</font>。
*   **每天晚上：** 每个收到“拒绝”回复的工作，把那个<font color="#ffff00">拒绝它的候选人</font>从它的偏好列表上划掉。

这个过程重复进行，直到没有新的拒绝产生。这意味着每个工作都向它的当前“待定”候选人发出了求婚，而所有候选人都保留了她们当前收到的最佳求婚。此时，每个候选人接受她们“待定”的工作，算法终止。

**算法在 $n=3$ 例子上的执行过程 (Note 中的表格):**
工作：AInc, BCo, CCorp (求婚方)
候选人：A, B, C (接收方)

偏好列表见前文。

*   **第 1 天早上：**
    *   AInc 的第一选择是 A。 AInc 向 A 求婚。*求婚不如说是发送 Offer*。
    *   BCo 的第一选择是 B。 BCo 向 B 求婚。
    *   CCorp 的第一选择是 A。 CCorp 向 A 求婚。
*   **第 1 天下午：**
    *   A 收到 AInc 和 CCorp 的求婚。 A 的偏好: BCo > AInc > CCorp. A 喜欢 AInc 胜过 CCorp. A 对 AInc 说“待定”，拒绝 CCorp。
    *   B 收到 BCo 的求婚。 B 的偏好: AInc > BCo > CCorp. B 对 BCo 说“待定”。
    *   C 没收到求婚。
*   **第 1 天晚上：** CCorp 被 A 拒绝，CCorp 把 A 从列表划掉。CCorp 的列表变为 B > C.

*   **第 2 天早上：**
    *   AInc 的最佳未被拒绝选择是 A。 AInc 向 A 求婚。（A 仍对 AInc “待定”）
    *   BCo 的最佳未被拒绝选择是 B。 BCo 向 B 求婚。（B 仍对 BCo “待定”）
    *   CCorp 的最佳未被拒绝选择是 B (A 已划掉)。 CCorp 向 B 求婚。
*   **第 2 天下午：**
    *   A 收到 AInc 的求婚。 A 对 AInc 说“待定”。
    *   B 收到 BCo 和 CCorp 的求婚。 B 的偏好: AInc > BCo > CCorp. B 喜欢 BCo 胜过 CCorp. B 对 BCo 说“待定”，<font color="#ffff00">拒绝 CCorp</font>。
    *   C 没收到求婚。
*   **第 2 天晚上：** CCorp 被 B 拒绝，CCorp 把 B 从列表划掉。CCorp 的列表变为 C.

*   **第 3 天早上：**
    *   AInc 向 A 求婚。（A 仍“待定”）
    *   BCo 向 B 求婚。（B 仍“待定”）
    *   CCorp 的最佳未被拒绝选择是 C。 CCorp 向 C 求婚。
*   **第 3 天下午：**
    *   A 收到 AInc 的求婚。 A 对 AInc 说“待定”。
    *   B 收到 BCo 的求婚。 B 对 BCo 说“待定”。
    *   C 收到 CCorp 的求婚。 C 对 CCorp 说“待定”。
*   **第 3 天晚上：** 没有新的拒绝。

<font color="#ffff00">算法终止。最终的匹配是每个人都在“待定”状态的配对：{(AInc, A), (BCo, B), (CCorp, C)}</font>.

回顾 Note 中的例子，输出匹配是 $$\text{{(Approximation Inc., Anita), (Basis Co., Bridget), (Control Corp., Christine)}}$$. 我的模拟结果是 $$\text{{(AInc, A), (BCo, B), (CCorp, C)}}$$. 咦，结果不一样？让我仔细检查一下 Note 中的表格。
Note 表格第一天：
A 收到 AInc, CCorp 邀约 -> A 对 AInc 说maybe，拒绝 CCorp.
B 收到 BCo 邀约 -> B 对 BCo 说maybe.
C 没收到邀约。
Note 表格第二天：
A 收到 AInc 邀约 -> A 对 AInc 说maybe. (AInc 还在求 A, 说明 A 对 AInc 是待定)
B 收到 BCo, CCorp 邀约 -> B 对 BCo 说maybe，拒绝 CCorp. (BCo 还在求 B, 说明 B 对 BCo 是待定；CCorp 在第一天被 A 拒绝后，第二天转而向 B 求婚)
C 没收到邀约。
Note 表格第三天：
A 收到 AInc 邀约 -> A 对 AInc 说maybe.
B 收到 BCo 邀约 -> B 对 BCo 说maybe.
C 收到 CCorp 邀约 -> C 对 CCorp 说maybe. (CCorp 在第二天被 B 拒绝后，第三天转而向 C 求婚)

最终匹配：(AInc, A), (BCo, B), (CCorp, C). 我的模拟是对的。Note 中的执行过程是对的，但它声称输出的是 {(Approximation Inc., Anita), (Basis Co., Bridget), (Control Corp., Christine)}，这与我的模拟和 Note 表格中的最终状态 {(AInc, A), (BCo, B), (CCorp, C)} 相符。Note 表格下面的输出匹配示例似乎打错了？或者是我看错了 Note 中的输出示例？

Note 中 Stable Matching example 是 {(Basis Co., Anita), (Approximation Inc., Bridget), (Control Corp., Christine)}.
Note 中 Algorithm output example 是 {(Approximation Inc., Anita), (Basis Co., Bridget), (Control Corp., Christine)}.
这两个是一样的，但与 Note 表格运行过程的结果 {(AInc, A), (BCo, B), (CCorp, C)} 不同。
让我再运行一遍，仔细核对偏好列表和 Note 表格。

Day 1:
AInc -> A
BCo -> B
CCorp -> A
A gets AInc, CCorp. Pref: BCo>AInc>CCorp. Chooses AInc. Rejects CCorp. A string: AInc.
B gets BCo. Pref: AInc>BCo>CCorp. Chooses BCo. B string: BCo.
C gets none.
Rejections: CCorp rejected by A. CCorp crosses A. CCorp list: B>C.

Day 2:
AInc -> A (AInc's best, A is on string)
BCo -> B (BCo's best, B is on string)
CCorp -> B (CCorp's best available, B>C)
A gets AInc. A string: AInc.
B gets BCo, CCorp. Pref: AInc>BCo>CCorp. B prefers BCo to CCorp. Chooses BCo. Rejects CCorp. B string: BCo.
C gets none.
Rejections: CCorp rejected by B. CCorp crosses B. CCorp list: C.

Day 3:
AInc -> A (A string: AInc)
BCo -> B (B string: BCo)
CCorp -> C (CCorp's best available, C)
A gets AInc. A string: AInc.
B gets BCo. B string: BCo.
C gets CCorp. C string: CCorp.
No rejections.

Algorithm terminates. Final matches are those on string: {(AInc, A), (BCo, B), (CCorp, C)}.

Ok,<font color="#ffff00"> the Note's example execution table is correct</font>, and the output matching listed *after* the table `{(Approximation Inc., Anita), (Basis Co., Bridget), (Control Corp., Christine)}` is *also* correct based on the table's final state. My initial reading of the example output string was wrong. The table is saying on Day 1, AInc and CCorp propose to Anita, Anita chooses AInc. BCo proposes to Bridget, Bridget chooses BCo. On Day 2, AInc still proposes to Anita, BCo still proposes to Bridget, CCorp (rejected by Anita) proposes to Bridget. Bridget chooses BCo. On Day 3, AInc-Anita, BCo-Bridget, CCorp (rejected by Bridget) proposes to Christine. Christine chooses CCorp. Final match: (AInc, Anita), (BCo, Bridget), (CCorp, Christine). Yes, the Note's table and final output match. My step-by-step reasoning for Day 1 and Day 2 rejections aligns with the table, but my Day 3 interpretation of CCorp's action might have been faulty. Let me re-trace Day 2 evening & Day 3 morning for CCorp:

Day 2 Evening: CCorp is rejected by B. CCorp crosses B off its list. CCorp's list becomes just C.
Day 3 Morning: CCorp proposes to its best available: C.
Day 3 Afternoon: C receives offer from CCorp. C accepts (puts on string).
Day 3 Evening: No rejections.

Final Matching: AInc with A, BCo with B, CCorp with C.
Wait... The Note table says on Day 3, AInc, BCo, CCorp *all* propose. Let's see who they propose to.
AInc: A (AInc's best choice, A holds AInc offer from Day 1)
BCo: B (BCo's best choice, B holds BCo offer from Day 1)
CCorp: C (CCorp was rejected by A (Day 1), then B (Day 2), C is only one left)
So, AInc->A, BCo->B, CCorp->C.
A gets AInc, holds AInc.
B gets BCo, holds BCo.
C gets CCorp, holds CCorp.
No one is rejected. Algorithm terminates. Match is {(AInc, A), (BCo, B), (CCorp, C)}.

Okay, I suspect there's a typo in the Note's example output matching *description* vs. the *table*. The table's final state clearly shows A matched with AInc, B with BCo, C with CCorp. The output matching description `{(Approximation Inc., Anita), (Basis Co., Bridget), (Control Corp., Christine)}` lists exactly these pairs. So the table and the output *do* match. My initial confusion came from recalling the *stable matching example* shown earlier `{(Basis Co., Anita), (Approximation Inc., Bridget), (Control Corp., Christine)}`, which is different. The algorithm output is `{(AInc, A), (BCo, B), (CCorp, C)}`. Let's re-check the stability of this *algorithm output* matching `{(AInc, A), (BCo, B), (CCorp, C)}`.

In `{(AInc, A), (BCo, B), (CCorp, C)}`:
AInc-A, BCo-B, CCorp-C.
AInc Pref: A>B>C. Current A.
BCo Pref: B>A>C. Current B.
CCorp Pref: A>B>C. Current C.

A Pref: BCo>AInc>CCorp. Current AInc.
B Pref: AInc>BCo>CCorp. Current BCo.
C Pref: AInc>BCo>CCorp. Current CCorp.

Potential rogue pairs $(J, C^*)$ where $J$ is not matched with $C^*$ and they are not current partners:
*   (AInc, B): AInc likes B > A (No).
*   (AInc, C): AInc likes C > A (No).
*   (BCo, A): BCo likes A > B (No).
*   (BCo, C): BCo likes C < B (No).
*   (CCorp, A): CCorp likes A > C. Yes. Candidate A is matched with AInc. Does A like CCorp > AInc? No, A prefers BCo > AInc > CCorp. So (CCorp, A) is NOT a rogue couple.
*   (CCorp, B): CCorp likes B > C. Yes. Candidate B is matched with BCo. Does B like CCorp > BCo? No, B prefers AInc > BCo > CCorp. So (CCorp, B) is NOT a rogue couple.

This matching `{(AInc, A), (BCo, B), (CCorp, C)}` *is* stable. And it is the output of the algorithm simulation shown in the table. My apologies for the confusion, the Note's example output description is correct and matches the table output.

现在我们理解了算法的流程和在例子上的运行。这个算法为什么总是有效呢？我们来证明它的重要性质。

**性质 1：算法总是终止 (halts)。**

**引理 4.1：求婚-拒绝算法总是终止。**
**证明思想：** 算法每次迭代（一天）都会发生什么？要么有人被拒绝，要么没有拒绝。如果没有拒绝，算法就终止了。如果有人被拒绝，那么至少有一个工作会把一个候选人从其偏好列表上划掉。一个工作-候选人的配对一旦被划掉，就永远不会再考虑了。总共有 $n$ 个工作和 $n$ 个候选人，所以总共有 $n \times n = n^2$ 对可能的 (工作, 候选人) 组合。每个工作在算法过程中最多向同一个候选人求婚一次（因为它一旦被拒绝，就会划掉这个候选人）。每个工作最多有 $n$ 个候选人可以求婚。总共可能发生的拒绝次数最多是 $n \times n = n^2$ 次 (每个工作对每个候选人最多拒绝一次)。每次拒绝都会导致某个工作划掉某个候选人。因此，划掉事件最多发生 $n^2$ 次。一旦某个工作列表上的所有人都被划掉了，它就没法再求婚了。最终，所有工作列表都会变空，或者所有工作都有人“待定”。这个过程是有限的，最多在 $n^2$ 次划掉后（或者说，至多 $n^2$ 天后，因为一天可能发生多次划掉）就会终止。所以算法总是终止的。$\square$

**性质 2：算法终止时，所有人都被匹配 (outputs a matching)。**

**引理 4.3：求婚-拒绝算法总是终止于一个匹配。**
**证明思想 (反证法):** 假设算法终止时，存在某个工作 J 没有被匹配。这意味着 J 在算法过程中向它偏好列表上的所有 $n$ 个候选人都求过婚，并且都被拒绝了。根据“改进引理”（我们稍后会证明），一旦一个候选人 C 收到一个工作 J 的求婚，在后续的每一天，C 手中都会有一个她喜欢程度至少和 J 一样的邀约。既然 J 向所有 $n$ 个候选人都求婚并被拒绝，这意味着这 $n$ 个候选人每个人都至少收到了 J 的求婚，并且在 J 被拒绝后，她们每个人手中都保留着一个她们比 J 更喜欢或者至少一样喜欢的邀约。当算法终止时，这些候选人手里的邀约就成为了她们最终的匹配对象。所以，这 $n$ 个候选人（A, B, C...）每个人都被一个工作匹配了。而且这些工作都不是 J (因为她们拒绝了 J)。所以，我们有 $n$ 个候选人，她们分别被 $n$ 个不同的工作匹配（因为每个人只能被一个工作匹配）。这样一来，除了 J 之外，其他 $n$ 个工作都必须被匹配了。但是我们总共只有 $n$ 个工作！这与“存在某个工作 J 没有被匹配”的假设矛盾。因此，算法终止时所有工作都必须被匹配，也就意味着所有候选人也被匹配，形成一个完整的匹配。$\square$

**性质 3：算法产生的匹配是稳定的。**

在我们证明稳定性之前，我们需要证明一个关于候选人待遇的关键引理。

**引理 4.2 (改进引理 - Improvement Lemma):** 如果工作 J 在第 $k$ 天向候选人 C 求婚，那么在之后的每一天，C 手中（待定）的邀约，她喜欢程度至少和 J 一样。
**证明思想 (归纳法):**
**基础情况 (i=k):** 在第 $k$ 天，C 收到了 J 的求婚（可能还有其他求婚）。在第 $k$ 天结束时，C 会把她收到的所有邀约中最好的那个设为“待定”。根据她的偏好，她保留的这个邀约，她喜欢的程度至少和 J 一样（因为 J 是她收到的选项之一）。引理成立。
**归纳假设:** 假设在某个任意的 $i \ge k$ 天，候选人 C 手中有一个工作 J' 的邀约（待定），她喜欢 J' 至少和 J 一样。
**归纳步骤:** 我们证明在第 $i+1$ 天引理也成立。根据算法，如果 J' 在第 $i$ 天是 C 的“待定”邀约，并且没有被 C 拒绝，那么在第 $i+1$ 天早上，J' 还会继续向 C 求婚（工作不会撤回邀约）。所以，在第 $i+1$ 天，C 至少会收到 J' 的求婚（可能还有其他新求婚）。在第 $i+1$ 天下午，C 会从她收到的所有求婚中选择最好的那个保留。她保留的这个新的“待定”邀约，她喜欢的程度会至少和 J' 一样。根据归纳假设，她喜欢 J' 至少和 J 一样。所以，她喜欢新的“待定”邀约，至少和 J 一样。引理对第 $i+1$ 天成立。
根据数学归纳法，引理对所有 $i \ge k$ 成立。$\square$

**关于良序原则 (Well-Ordering Principle) 的旁注:**
Note 中提到了引理 4.2 的另一种证明方式，使用了“第一个反例”的思想。这种思想依赖于自然数的一个非常特殊的性质：**良序原则 (Well-Ordering Principle)**。

> [!important] 
> **定义 4.1 (良序原则):** 任何非空的自然数集合都有一个最小元素。

自然数集 $\mathbb{N} = \{0, 1, 2, \dots\}$ (或者 $\{1, 2, \dots\}$ 取决于定义，在这里是后者 $\{1, 2, \dots\}$ 因为讨论的是“天数”) 满足良序原则。
**Sanity Check:**
*   $S_1 = \{5, 2, 11, 7, 8\}$. 最小元素是 2。
*   $S_2 = \{n \in \mathbb{N} : n \text{ is odd}\}$. 奇数集 $\{1, 3, 5, \dots\}$. 最小元素是 1。
*   $S_3 = \{n \in \mathbb{N} : n \text{ is prime}\}$. 素数集 $\{2, 3, 5, 7, \dots\}$. 最小元素是 2。
这些非空的自然数子集都有最小元素。

在“第一个反例”证明中，我们假设引理不总是成立，那么存在一些天 $i > k$ 是反例（C 持有的邀约差于 J）。我们将所有这样的天 $i$ 组成一个集合 S。如果 S 非空，根据良序原则，S 必定有一个最小元素，我们称之为 $i_{min}$。那么 $i_{min}$ 就是**第一个**引理不成立的日子。然后在 $i_{min}$ 这一天进行分析，导出矛盾。这种证明结构与归纳法是等价的。归纳法从基础情况 P(k) 和 P(i) => P(i+1) 推导出对所有 i>=k 成立。而“第一个反例”法是假设存在反例，找出第一个反例 $i_{min}$，然后证明在 $i_{min}$ 这一天一定不会出现反例（因为 $i_{min}-1$ 天是成立的），从而导致矛盾，说明反例集合 S 必须是空的，即引理对所有 i>=k 成立。

**Sanity Check:**
*   **整数集 $\mathbb{Z} = \{\dots, -2, -1, 0, 1, 2, \dots\}$:** 不满足良序原则。例如，负整数集合 $\{\dots, -3, -2, -1\}$ 是 $\mathbb{Z}$ 的非空子集，但没有最小元素。
*   **实数集 $\mathbb{R}$:** 不满足良序原则。例如，开区间 $(0, 1)$ 是 $\mathbb{R}$ 的非空子集，但没有最小元素（不存在一个最小的正实数）。
*   **非负实数集 $\mathbb{R}_{\ge 0}$:** 不满足良序原则。例如，开区间 $(0, 1)$ 是 $\mathbb{R}_{\ge 0}$ 的非空子集，但没有最小元素。

回到算法的稳定性证明。

**定理 4.1：算法产生的匹配总是稳定的。**
**证明思想 (直接证明):** 我们需要证明算法输出的匹配中不存在流氓伴侣。
假设算法输出的匹配是 $M$。考虑任意一对 (J, C*)，她们在 $M$ 中不是伴侣。为了成为流氓伴侣，需要满足两个条件：
1.  J 喜欢 C* 胜过它在 $M$ 中的伴侣 C。
2.  C* 喜欢 J 胜过她在 $M$ 中的伴侣 J*。

我们要证明对于算法输出的匹配 $M$，如果条件 1 成立，那么条件 2 一定不成立。也就是说，如果 J 喜欢 C* 胜过它的伴侣 C，那么 C* 一定**不**喜欢 J 胜过她的伴侣 J* (即 C* 喜欢 J* 至少和 J 一样)。

假设 J 喜欢 C* 胜过它在 $M$ 中的伴侣 C。根据算法流程，工作 J 是按偏好顺序向候选人求婚的。既然 J 最终和 C 匹配了，并且它喜欢 C* 胜过 C，那么 J 一定曾经向 C* 求婚（因为 C* 在 J 的偏好列表上排在 C 的前面）。
既然 J 向 C* 求婚了，根据**改进引理 (Lemma 4.2)**，从 J 求婚的那天起，候选人 C* 手中持有的邀约，她喜欢程度至少和 J 一样。当算法最终终止时，C* 持有的这个邀约就是她的最终伴侣 J*。因此，C* 喜欢她的最终伴侣 J* 至少和 J 一样。
<font color="#ffff00">这意味着 C* **不**喜欢 J 胜过她的伴侣 J*。所以条件 2 不成立。</font>
因此，任何满足条件 1 的对 (J, C*) 都不能满足条件 2。这证明了算法输出的匹配中不存在流氓伴侣。所以，算法产生的匹配是稳定的。$\square$

注意到这个证明是从工作的角度出发的：如果工作想“挖墙脚”，我们证明候选人不会被挖走。

### 优化性 (Optimality)

我们已经证明了算法总是能找到一个稳定的匹配。但是，如果存在多个稳定匹配呢？不同的稳定匹配对工作和候选人来说，满意程度可能是不同的。有没有一个稳定匹配能让工作方集体满意度最高？或者让候选人方集体满意度最高？

Note 中给了一个 $n=4$ 的例子：
工作：1, 2, 3, 4
候选人：A, B, C, D

偏好列表：
Jobs   Candidates
1      A > B > C > D
2      A > D > C > B
3      A > C > B > D
4      A > B > C > D

Candidates   Jobs
A      1 > 3 > 2 > 4
B      4 > 3 > 2 > 1
C      2 > 3 > 1 > 4
D      3 > 4 > 2 > 1

Note 中说有两个稳定匹配：
$S = \{(1,A), (2,D), (3,C), (4,B)\}$
$T = \{(1,A), (2,C), (3,D), (4,B)\}$

我们来定义一下最优的概念。

**定义 4.2 (工作的最优候选人 - Optimal candidate for a job):** 对于一个工作 J，它的最优候选人 C 是指，在**所有**可能的稳定匹配中，J 能匹配到的、它偏好列表上排名最高的候选人。
**换句话说，一个工作 J 的最优候选人，是在稳定性的限制下，J 能得到的最好的结果。**

**Sanity Check (n=4 例子):**
工作 1 的偏好：A > B > C > D。在稳定匹配 S 中，1 匹配 A；在稳定匹配 T 中，1 匹配 A。A 是 1 的第一选择。如果 1 能匹配到 A，这当然是它最好的结果。A 是 1 的最优候选人吗？是的，因为在至少一个稳定匹配（S 和 T）中，1 匹配了 A，而且 A 是它第一选择。
工作 2 的偏好：A > D > C > B。在 S 中 2 匹配 D，在 T 中 2 匹配 C。2 喜欢 D 胜过 C。2 的第一选择是 A。有没有稳定匹配让 2 匹配 A？ Note 中说“没有稳定匹配让 2 匹配 A”。那么 2 的最优候选人是 D 还是 C？根据定义，是最偏好的那个。在 S 中是 D，在 T 中是 C。D 比 C 靠前。所以在所有稳定匹配中，2 最好能匹配到 D。2 的最优候选人是 D。
工作 3 的偏好：A > C > B > D。在 S 中 3 匹配 C，在 T 中 3 匹配 D。3 喜欢 C 胜过 D。3 的最优候选人是 C。
工作 4 的偏好：A > B > C > D。在 S 中 4 匹配 B，在 T 中 4 匹配 B。4 喜欢 B 胜过 C, D。4 的最优候选人是 B。

所以，每个工作的最优候选人是：
1: A
2: D
3: C
4: B

注意到稳定匹配 $$S = \text{\{(1,A), (2,D), (3,C), (4,B)\}}$$ 正是每个工作都与其最优候选人匹配的那个匹配。我们称这样的匹配为**工作最优匹配 (job/employer optimal matching)**。

类似地，我们可以定义候选人的最优工作。
**定义 4.3 (候选人的最优工作 - Optimal job for a candidate):** 对于一个候选人 C，她的最优工作 J 是指，在**所有**可能的稳定匹配中，C 能匹配到的、她偏好列表上排名最高的工作。
**换句话说，一个候选人 C 的最优工作，是在稳定性的限制下，C 能得到的最好的结果。**

**Sanity Check (n=4 例子):**
A 的偏好：1 > 3 > 2 > 4。在 S 中 A 匹配 1，在 T 中 A 匹配 1。1 是 A 的第一选择。A 的最优工作是 1。
B 的偏好：4 > 3 > 2 > 1。在 S 中 B 匹配 4，在 T 中 B 匹配 4。4 是 B 的第一选择。B 的最优工作是 4。
C 的偏好：2 > 3 > 1 > 4。在 S 中 C 匹配 3，在 T 中 C 匹配 2。C 喜欢 2 胜过 3。C 的最优工作是 2。
D 的偏好：3 > 4 > 2 > 1。在 S 中 D 匹配 2，在 T 中 D 匹配 3。D 喜欢 3 胜过 2。D 的最优工作是 3。

所以，每个候选人的最优工作是：
A: 1
B: 4
C: 2
D: 3

稳定匹配 $T = \{(1,A), (2,C), (3,D), (4,B)\}$.
(1,A): A 的最优工作是 1。
(2,C): C 的最优工作是 2。
(3,D): D 的最优工作是 3。
(4,B): B 的最优工作是 4。
注意 (4,B) 这里的 B 匹配 4，4 是 B 的最优工作。
是的，稳定匹配 T 正是每个候选人都与其最优工作匹配的那个匹配。我们称这样的匹配为**候选人最优匹配 (candidate optimal matching)**。

我们还可以定义“最差”的概念。
**工作的最差候选人 (pessimal candidate for a job):** 在所有稳定匹配中，工作 J 能匹配到的、它偏好列表上排名**最低**的候选人。
**工作的最差匹配 (employer pessimal matching):** 每个工作都与其最差候选人匹配的稳定匹配。
类似地，有候选人的最差工作和候选人最差匹配。在 $n=4$ 的例子中，稳定匹配 S 是工作最优匹配，稳定匹配 T 是候选人最优匹配。S 对工作方更有利，T 对候选人方更有利。

那么，求婚-拒绝算法（以工作为求婚方）产生的匹配是哪种最优呢？

> [!important] 
> **定理 4.2：求婚-拒绝算法输出的匹配是工作/雇主最优的。**
> **证明思想 (反证法，利用“第一个反例”和良序原则):**

假设算法输出的匹配 $M$ 不是工作最优的。这意味着至少有一个工作 J 没有匹配到它的最优候选人 C*。根据最优候选人的定义，存在一个稳定匹配 $T$ 中，J 和 C* 是伴侣。
考虑算法的执行过程。工作 J 是按偏好顺序向候选人求婚的。 যেহেতু J 最终没有匹配到 C*，并且 C* 是 J 的最优候选人（在 $T$ 中与 J 匹配），那么 J 在算法过程中一定曾经向 C* 求过婚，但后来因为某些原因（C* 接受了另一个工作 J* 的邀约）而放弃了 C*。所以 J 一定被 C* 拒绝过。

假设第 $k$ 天是算法执行过程中，**第一次**有工作被它的最优候选人拒绝。设在第 $k$ 天，工作 J 被它的最优候选人 C* 拒绝了，原因是因为 C* 接受了工作 J* 的邀约（并将 J* 设置为“待定”）。
因为 C* 拒绝了 J 而选择了 J*，根据算法规则，C* 肯定喜欢 J* 胜过 J。
现在，考虑存在一个稳定匹配 $T$ 中，J 和 C* 是伴侣。在 $T$ 中，工作 J* 的伴侣不是 C* (因为 C* 在 $T$ 中是 J 的伴侣)，假设 J* 在 $T$ 中的伴侣是 C'。即 $T = \{\dots, (J, C^*), \dots, (J^*, C'), \dots\}$。
我们现在要证明在稳定匹配 $T$ 中存在一个流氓伴侣 $(J^*, C^*)$，从而导致矛盾。要证明 $(J^*, C^*)$ 是 T 中的流氓伴侣，需要：
1.  C* 喜欢 J* 胜过她在 $T$ 中的伴侣 J。我们已经知道了：C* 在算法第 $k$ 天拒绝了 J 而选择了 J*，所以 C* 喜欢 J* 胜过 J。这一点成立。
2.  J* 喜欢 C* 胜过它在 $T$ 中的伴侣 C'。这是关键点。

我们知道第 $k$ 天是**第一个**有工作被它的最优候选人拒绝的日子。这意味着在第 $k$ 天之前，**没有任何一个工作被它的最优候选人拒绝过**。工作 J* 在第 $k$ 天向 C* 发出了邀约（并被 C* 接受），这说明在 J* 的偏好列表中，C* 至少与 J* 的最佳可用候选人（在第 $k$ 天早上还没拒绝过 J* 的候选人中排名最高的那个）一样好。
如果 C* 不是 J* 的最优候选人，那么 J* 的最优候选人 C\_opt 一定是某个 J* 更喜欢的候选人，而且 C\_opt 在 J* 的偏好列表中排在 C* 前面。

但如果 C\_opt 确实在 C* 前面，J* 应该先向 C\_opt 求婚。如果在第 $k$ 天 J* 向 C* 求婚，说明所有 J* 比 C* 更喜欢的候选人（包括 C\_opt，如果它排在 C* 前面）要么已经被 J* 求婚过但拒绝了 J*，要么已经跟某个 J* 无法撼动的工作匹配了。
根据我们的“第一个反例”假设，在第 $k$ 天之前，没有任何工作被其最优候选人拒绝。这意味着，如果在第 $k$ 天之前 J* 向 C\_opt 求婚过，C\_opt 不可能拒绝 J* 如果 C\_opt 是 J* 的最优候选人（因为这会构成一个更早的“工作被最优候选人拒绝”的反例）。所以，如果 C\_opt 是 J* 的最优候选人且排名在 C* 前面，C\_opt 不可能在第 $k$ 天前拒绝 J*。这导致矛盾。
唯一的可能性是，在第 $k$ 天 J* 向 C* 求婚时，C* 是 J* 仍然可以追求的、排名最高的候选人，并且 C* 至少与 J* 的最优候选人一样好。
既然 J* 的最优候选人是 J* 在**任何**稳定匹配中能得到的最好的伴侣，那么 J* 喜欢 C* 至少和它的最优候选人一样，也就意味着 J* 喜欢 C* 至少和它在稳定匹配 T 中的伴侣 C' 一样好。

所以，J* 喜欢 C* 至少和 C' 一样。结合 C* 喜欢 J* 胜过 J，我们在稳定匹配 T 中找到了流氓伴侣 $(J^*, C^*)$。这与 T 是稳定匹配矛盾。
因此，最初的假设（算法输出的匹配不是工作最优的）是错误的。算法输出的匹配一定是工作最优的。$\square$

**良序原则在哪里使用了？** 在“假设第 $k$ 天是**第一次**有工作被它的最优候选人拒绝”这句话中。如果存在这样的日子，那么根据良序原则，一定存在一个最小的这样的日子 $k$。

这个定理证明了工作/雇主在这种算法中具有优势，它们能得到所有稳定匹配中对它们最有利的结果。

那么，这对候选人意味着什么呢？

> [!important] 
> **定理 4.3：如果一个匹配是工作/雇主最优的，那么它也是候选人最差的。**
> **证明思想 (反证法):**

设 $M$ 是工作最优匹配（由算法产生）。假设 $M$ 不是候选人最差的。这意味着存在一个候选人 C，她在 $M$ 中匹配到的工作是 J，即 $(J, C) \in M$，但是存在另一个稳定匹配 $S$，其中 C 匹配到了一个她更喜欢的工作 J*。即 $(J^*, C) \in S$，并且 C 喜欢 J* 胜过 J。在稳定匹配 $S$ 中，J 必须与某个候选人 C' 匹配，即 $(J, C') \in S$。

我们现在要证明在稳定匹配 $S$ 中存在一个流氓伴侣 $(J, C)$，从而导致矛盾。要证明 $(J, C)$ 是 S 中的流氓伴侣，需要：
1.  C 喜欢 J 胜过她在 $S$ 中的伴侣 J*。
2.  J 喜欢 C 胜过它在 $S$ 中的伴侣 C'。

首先看条件 1：C 喜欢 J 胜过 J*。我们的假设是 C 喜欢 J* 胜过 J（因为 J* 在 C 的偏好列表上排名更高）。所以条件 1 不成立。
Wait, the theorem statement and proof setup in the Note are critical here. Let's re-read: "Suppose... there exists a stable matching $S = \{\dots, (J^*, C), \dots, (J, C'), \dots\}$ such that job $J^*$ is lower-ranked on C’s preference list than job $J$ (i.e., J is not her pessimal job)."
这个设定是说，存在一个稳定匹配 $S$ 中，C 匹配到了 J*，而 J* 在 C 的偏好列表上比 J 排名**低**。也就是说，**C 喜欢 J 胜过 J***。
这正是我们在证明 (J, C) 是 S 中流氓伴侣所需要的条件 1。C 喜欢 J 胜过 J*。这个条件成立。

现在看条件 2：J 喜欢 C 胜过它在 S 中的伴侣 C'。
在工作最优匹配 $M$ 中，(J, C) 是伴侣。根据工作最优匹配的定义，C 是工作 J 的**最优候选人**。最优候选人是工作 J 在**任何**稳定匹配中能匹配到的最好的伴侣。既然 $S$ 是一个稳定匹配，工作 J 在 $S$ 中的伴侣 C'，其排名在 J 的偏好列表上，一定不可能比它的最优伴侣 C 排名更高。也就是说，J 喜欢 C 至少和 C' 一样好。实际上，由于 C 是 J 的最优伴侣，J 除非在所有稳定匹配中都只匹配到 C'（这使得 C'=Copt=C），否则 J 会严格偏好 C 胜过 C' (如果 C' != C)。如果 C'=C，那 (J,C) 就在S中配对了，也就不是流氓伴侣了。所以 C' 必须不同于 C. 既然 C 是 J 的最优候选人，而 C' 是 J 在稳定匹配 S 中的伴侣 (C' != C)，J 必须严格偏好 C 胜过 C'。
所以条件 2：J 喜欢 C 胜过 C'，成立。

两个条件都成立：C 喜欢 J 胜过 J*，且 J 喜欢 C 胜过 C'。因此，(J, C) 构成稳定匹配 S 中的一个流氓伴侣。这与 S 是稳定匹配矛盾。
因此，最初的假设（工作最优匹配不是候选人最差的）是错误的。工作最优匹配一定是候选人最差的。$\square$

**这意味着什么？** 以工作为求婚方运行 Gale-Shapley 算法，得到的结果对工作方是最好的（在所有稳定匹配中），但对候选人方却是最差的（在所有稳定匹配中）。这是一个非常深刻的结论，它揭示了算法设计中的**权力分配**。求婚方在结果上占优。

**练习：** 要想让算法输出一个候选人最优匹配，应该怎么修改算法？
答案：让候选人向工作求婚。

这个发现对理解现实世界的匹配系统（比如住院医师匹配）非常有意义。最初，住院医师匹配是医院（类似工作）向学生（类似候选人）发邀约，所以匹配结果是医院最优（对学生来说是最差的稳定匹配）。后来，为了改善学生的处境，NRMP 修改算法，让学生向医院表达偏好（类似学生求婚），这样产生的稳定匹配就变成了学生最优（对医院来说是最差的稳定匹配）。这个改动在自动化系统内部实现相对容易，如果在现实世界中让学生直接与医院谈判，学生的议价能力远低于医院，很难自发达成对学生有利的结果。这说明，巧妙的算法设计和制度结构可以在一定程度上平衡甚至扭转现实世界的权力不对称。

### 知识点总结与要点提炼

*   **问题定义：** 在有偏好列表的两组（工作和候选人）之间寻找一对一匹配。
*   **稳定性：** 关键标准是匹配中不存在流氓伴侣（未匹配对 J 和 C*，J 喜欢 C* 胜过当前，C* 喜欢 J 胜过当前）。
*   **室友问题：** 同质类型的个体之间可能不存在稳定匹配，凸显了工作/候选人模型中类型不对称的重要性。
*   **求婚-拒绝算法 (Gale-Shapley):**
    *   一方（如工作）按偏好顺序向另一方（候选人）求婚。
    *   接收方（候选人）保留最好的邀约，拒绝其他的。
    *   被拒绝的求婚方转向偏好列表上的下一个。
    *   重复直至没有拒绝。
*   **算法性质：**
    *   总是**终止**（至多 $n^2$ 天/拒绝）。
    *   总是输出一个完整的**匹配**（所有人都被配对）。
    *   产生的匹配总是**稳定**的。
*   **最优性：**
    *   存在多个稳定匹配时，“最优”和“最差”是相对于所有稳定匹配而言的最好/最差结果。
    *   以工作为求婚方的算法输出**工作最优匹配**（对工作方集体最优）。
    *   工作最优匹配同时是**候选人最差匹配**（对候选人方集体最差）。
*   **核心思想：** 算法的性质和结果（谁最优谁最差）取决于哪一方是求婚方。求婚方享有“最优”优势。

### 学科思想与延伸思考

这个稳定匹配问题和 Gale-Shapley 算法是算法设计和离散数学中一个经典的、非常优美的例子。它展示了：
1.  **建模的力量：** 将现实世界的问题（婚配、实习分配、住院医师匹配）抽象为数学模型（图、偏好列表、匹配）。
2.  **算法的威力：** 一个看似简单直观的迭代过程，竟然能保证找到一个具有重要性质（稳定、最优）的解。
3.  **存在性与构造性：** 算法的成功不仅证明了稳定匹配的存在性（因为它构造了一个），而且提供了一个找到它的有效方法。
4.  **制度设计：** 算法规则的设计（谁求婚，谁拒绝）直接影响了最终结果的分配性质，这在设计市场或其他分配机制时具有深刻的指导意义。Gale 和 Shapley 因此获得了诺贝尔经济学奖，正因为他们的工作揭示了算法在经济匹配理论和实践中的价值。

正如 Note 中提到的，这个领域还有很多后续研究，比如考虑有容量限制的工作（一个医院可以招多个住院医）、有重复（学生可以申请多个岗位）、以及更复杂的偏好结构（比如已婚夫妇希望匹配在同一城市或附近）。这些都是活跃的研究方向。

希望这次讲解能帮助大家理解稳定匹配问题的核心概念、算法流程以及其重要的性质和背后的思想。它是一个非常精彩的结合了数学、计算机科学和经济学的例子。

如果大家对其中的证明细节或者例子有任何疑问，或者想进一步探讨它的实际应用，随时可以提出！