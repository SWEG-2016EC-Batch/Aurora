


graph TD
    A[Start] --> B{Input weight (kg) and height (m)};
    B --> C[Calculate BMI = weight / (height*height)];
    C --> D[Display BMI];
    D --> E{Is BMI < 18.5?};
    E -- Yes --> F[Display: Underweight];
    E -- No --> G{Is BMI <= 24.9?};
    G -- Yes --> H[Display: Normal weight];
    G -- No --> I{Is BMI <= 29.9?};
    I -- Yes --> J[Display: Overweight];
    I -- No --> K[Display: Obese];
    F --> L{Continue?};
    H --> L;
    J --> L;
    K --> L;
    L -- Yes --> B;
    L -- No --> M[End];



