## 🔹 What This Does

Chase: LEDs turn on one by one from left → right.

Bounce: LEDs go left → right → left.

Blink: All LEDs blink together.

## 🔹 Why Static?

The LED pins (pins[]) are shared by all light modes → so we use static properties/methods.

We don’t need multiple RunningLights objects. Instead, we treat it like a utility class.