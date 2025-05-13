### 知识回顾

> [!important] 
> **混淆矩阵 (Confusion Matrix)**：
> 
> |                     | 预测为正 (Predicted Positive) | 预测为负 (Predicted Negative) |
> | :------------------ | :---------------------------: | :---------------------------: |
> | **实际为正 (Actual Positive)** |   TP (True Positive) 正确预测为正   |   FN (False Negative) 错误预测为负 (漏报)   |
> | **实际为负 (Actual Negative)** |   FP (False Positive) 错误预测为正 (误报)   |   TN (True Negative) 正确预测为负   |
> 

基于这个矩阵，定义：

*   **准确率 (Accuracy):** 预测正确的样本占总样本的比例。
    $$ \text{Accuracy} = \frac{TP + TN}{TP + FN + FP + TN} $$
*   **精确率 (Precision):** 在所有被模型预测为“正类”的样本中，有多少是真的“正类”。$$ \text{Precision} = \frac{TP}{TP + FP} $$    (注意：如果 $TP+FP=0$，即模型从未预测过正类，Precision 通常定义为 0 或 1，需要根据情况讨论)
*   **召回率 (Recall) / 敏感度 (Sensitivity):** 在所有真正的“正类”样本中，有多少被模型成功预测出来了。$$ \text{Recall} = \frac{TP}{TP + FN} $$
*   **F1 值 (F1 Score):** Precision 和 Recall 的调和平均数，是它们的综合评价指标。
    $$ F1 = \frac{2 \times \text{Precision} \times \text{Recall}}{\text{Precision} + \text{Recall}} = \frac{2TP}{2TP + FP + FN} $$
    (调和平均更关注较小的值，因此 F1 要求 Precision 和 Recall 都比较高)

根据定义，完成Python代码：

```python
import numpy as np

class EvaluationMetrics(object):
    
    def confusion_matrix(self, y_true, y_pred):
        #补全该方法
        TP, FP, TN, FN = 0, 0, 0, 0
        for term in range(len(y_true)):
            if y_true[term] and y_pred[term]:
                TP += 1
            elif y_true[term] and not y_pred[term]:
                FN += 1
            elif not y_true[term] and y_pred[term]:
                FP += 1
            else:
                TN += 1
        return TP, FP, TN, FN
    
    def accuracy(self, y_true, y_pred):
        #补全该方法
        TP, FP, TN, FN = self.confusion_matrix(y_true, y_pred)
        return (TP + TN) / (TP + FN + FP + TN)
    
    def precision(self, y_true, y_pred):
        #补全该方法
        TP, FP, TN, FN = self.confusion_matrix(y_true, y_pred)
        return TP / (TP + FP)
        
    def recall(self, y_true, y_pred):
        #补全该方法
        TP, FP, TN, FN = self.confusion_matrix(y_true, y_pred)
        return TP / (TP + FN)

    def f1(self, y_true, y_pred):
        #补全该方法
        TP, FP, TN, FN = self.confusion_matrix(y_true, y_pred)
        return 2*TP / (2*TP + FN + FP)
```

















结果如下图所示：
截图自 VSCode 运行界面，结果与最初打开文件时所得相同。

![[Pasted image 20250512203751.png]]