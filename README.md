# **Week8Table – Rebalancing Pattern (Components & Uses)**

## **Rebalancing Pattern – Components**

| Component | Short Description |
|-----------|-------------------|
| **Dataset** | Stores the original data, labels, and number of classes. Acts as the source structure before rebalancing. |
| **Rebalancer** | Performs the rebalancing operation (e.g., oversampling, undersampling, weighting). Provides access to rebalanced data and labels through helper methods. |
| **BaseModel** | Generic machine learning model with core operations like train(), predict(), and evaluate(). Serves as a reusable foundation for model logic. |
| **RebalancedModel** | Extends BaseModel by integrating a Rebalancer. Uses rebalanced data for training, prediction, and evaluation, ensuring the model learns from a corrected distribution. |

---

## **Rebalancing Pattern – Common Usage**

| Domain | How Rebalancing Helps |
|--------|------------------------|
| **Fraud Detection** | Fraud cases are rare; rebalancing increases representation of fraudulent examples so models don't ignore them and can detect fraud accurately. |
| **Medical Diagnosis** | Rare diseases have few samples; rebalancing prevents the model from favoring the majority (healthy) class and improves detection of rare conditions. |
| **Anomaly Detection** | Outliers occur infrequently; rebalancing ensures the model learns to recognize abnormal patterns rather than defaulting to normal predictions. |
| **Credit Risk Assessment** | Default events are scarce; rebalancing helps models correctly identify potential defaulters rather than always predicting “no default.” |
