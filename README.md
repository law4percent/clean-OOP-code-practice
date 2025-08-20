# Running Lights (Arduino OOP)

Different ways to design **LED running light patterns** in Arduino using
**OOP principles**.

This project compares two approaches:
1. **Static Class Approach**
2. **Instance-Based Class Approach**

------------------------------------------------------------------------

## 🔹 Static Class Approach

### Concept

-   A class acts like a **utility** with `static` properties and
    methods.
-   LED pins and behaviors are **shared across all methods**.
-   No need to instantiate objects.

### ✅ Advantages

-   Simple and straightforward for **small projects**.
-   Easy to call methods like `RunningLights::chase(200)`.
-   All LEDs share the same configuration (centralized).

### ⚠️ Disadvantages

-   **Not reusable** if you want multiple LED groups (hardcoded pin
    array).
-   Violates **Single Responsibility Principle** if the class keeps
    growing.
-   Behaves more like a **namespace** than a true object.

### 📌 Example Use Case

-   Quick demo projects.
-   Classroom exercises where you only use **one LED strip**.

------------------------------------------------------------------------

## 🔹 Instance-Based Class Approach

### Concept

-   Each object manages its own set of LEDs.
-   Configuration (pins, number of LEDs) is passed via constructor.
-   Methods operate on the **instance's state**.

### ✅ Advantages

-   **Reusable** → different LED strips can be managed by different
    objects.
-   **Encapsulation** → each object keeps its own pins and behavior.
-   Aligns with **Clean Code & SOLID principles** (esp. Single
    Responsibility).
-   More **scalable** for bigger projects.

### ⚠️ Disadvantages

-   Slightly more complex to set up.
-   Requires object creation (`RunningLights lights(pins, 5);`).

### 📌 Example Use Case

-   Multiple LED strips (e.g., headlights + taillights simulation).
-   Projects needing **flexible configurations** (change pins easily).
-   Larger Arduino systems where **clean design matters**.

------------------------------------------------------------------------

## 🔹 Summary

| Feature | Static Approach | Instance Approach |
|---|---|---|
| Reusability | ❌ Limited (one fixed LED set) | ✅ Multiple LED groups supported |
| Clean Code Practice | ⚠️ Less clean (acts like namespace) | ✅ More OOP, SOLID-friendly |
| Simplicity | ✅ Very simple | ⚠️ Slightly more setup |
| Best for | Small demos, quick tests | Scalable, reusable, maintainable code |


## 🚦 Recommendation

-   Use **Static Approach** if you just want to **quickly test LED
    effects**.\
-   Use **Instance Approach** if you care about **clean code,
    reusability, and scalability**.
