| **Topic** | **Concise Explanation (Exam-Ready)** |
|----------|---------------------------------------|
| **Distribution Strategy – What It Is** | A pattern that speeds up training by splitting data across **multiple GPUs/machines**, synchronizing gradients, and updating a shared global model. Allows training models too large for a single device. |
| **Why It’s Used** | Reduces training time, scales to massive datasets, enables training of huge models, maximizes GPU/cluster efficiency. |
| **Key Components (UML Roles)** | **Central Server (Parameter Server):** Aggregates gradients, updates global model. **Worker:** Trains on data partitions, computes gradients. **Data Partitioner:** Splits data into worker batches. |
| **Common Usage** | Production ML pipelines, AutoML parallel trials, preprocessing pipelines (vision/NLP), feature engineering for huge datasets, large-scale model training (LLMs, CNNs). |
| **Typical Exam Justification Points** | 1) Allows parallel computation across hardware. 2) Handles memory-heavy models. 3) Ensures synchronized/global model convergence. |
| **Distribution Strategy vs Parallel Processing** | **Parallel Processing:** Tasks are independent; no shared model. Minimal communication. **Distribution Strategy:** Workers share gradients/parameters; high communication; required for ML convergence. |
| **Analogy (Often Asked)** | *Parallel processing:* many cooks making separate dishes. *Distribution strategy:* many cooks making *the same dish*, constantly synchronizing ingredients. |
| **When to Use Which** | Use **parallel processing** for independent tasks (file processing). Use **distribution strategy** for **shared ML models** needing synchronized updates. |


