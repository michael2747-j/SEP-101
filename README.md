| **Section** | **Content** |
|------------|-------------|
| **Extracted Question** | *“Write the **RebalancedModel** class (pseudo-code is allowed) based on the provided Dataset, Rebalancer, and BaseModel classes. Also explain what this design pattern is attempting to do.”* |
| **Pattern Purpose** | The Rebalancing Pattern ensures ML models train on **balanced datasets**, preventing bias toward majority classes. A RebalancedModel wraps a base model and automatically applies a Rebalancer before training, producing fairer and more reliable predictions. |
| **Why This Pattern Is Used** | • Avoids majority-class bias by training on equalized class distributions. <br> • Keeps data-balancing logic **separate** from model logic (clean architecture). <br> • Makes models reusable and consistent across different datasets with varying imbalance levels. |
| **RebalancedModel Responsibilities** | The RebalancedModel extends BaseModel and contains a Rebalancer and a BaseModel. On `train()`, it rebalances the dataset then calls the base model’s training logic; on `predict()`, it delegates to the base model. |
| **Dataset Class** | Stores original features and labels; calculates number of classes. Provides getters: `get_data()`, `get_labels()`, `get_num_classes()`. |
| **Rebalancer Class** | Encapsulates oversampling/undersampling logic. Its method `rebalance(dataset)` returns a **new balanced Dataset**. |
| **BaseModel Class** | Abstract ML model interface defining: `train()`, `predict()`, and optionally `evaluate()`. Used as the model being wrapped. |
| **Summary (Exam Sentence)** | *“RebalancedModel wraps a base model with a Rebalancer so training uses a rebalanced dataset, improving fairness and performance on minority classes without modifying the core model.”* |

