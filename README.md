| **Topic** | **Concise Explanation (Exam-Ready)** |
|----------|---------------------------------------|
| **Checkpoints Pattern – What It Is** | A pattern that periodically saves the full training state (model weights, optimizer, epoch, metadata) so training can **resume** after interruption instead of restarting from scratch. Ensures reliability, reproducibility, and efficiency in long-running ML jobs. |
| **Why It’s Used** | Prevents loss of training progress, supports early stopping/model selection, enables training on unstable hardware (cloud GPUs), and reduces compute waste. |
| **Key Components (UML Roles)** | **Trainer:** Runs training loop and delegates checkpointing. **CheckpointManager:** Decides when to save/restore states. **ModelState:** Stores minimal info needed to resume. **Storage Interface:** Abstracts saving/loading. **LocalStorage / CloudStorage:** Implement storage backends. |
| **Common Usage** | Deep learning frameworks (TF/PyTorch) for long model training, distributed systems (Spark/Hadoop), streaming pipelines (Flink/Kafka), HPC simulations (NASA/CERN), databases (Postgres WAL-like recovery). |
| **Typical Exam Justification Points** | 1) Improves fault-tolerance and training continuity. 2) Saves compute costs and avoids restarting from epoch 0. 3) Makes experiments reproducible and manageable. |
| **Memento vs Checkpoints** | **Memento:** Small in-memory rollback for a single object (undo). **Checkpoint:** Heavy, persistent snapshot for whole ML pipeline; used for crash recovery & resumption, not undo. |
| **Transfer Learning – What It Is** | A pattern where a model trained on a large dataset is reused for a new task by **freezing early layers** and adding **new task-specific layers**. Enables training with limited data. |
| **Why It’s Used** | Reduces training time, boosts accuracy with small datasets, uses general features learned from large models (e.g., ImageNet, BERT). |
| **Key Components (UML Roles)** | **Pretrained Model:** Provides reusable feature extractor. **New Task-Specific Model:** Adds new layers, fine-tunes for target task. |
| **Common Usage** | Image classification, object detection, NLP (BERT/GPT fine-tuning), speech recognition, anomaly detection, recommender systems. |
| **Typical Exam Justification Points** | 1) Avoids training from scratch. 2) Requires less data. 3) Improves performance via reused learned features. |

