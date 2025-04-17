---
sr-due: 2025-04-13
sr-interval: 4
sr-ease: 270
---

#review 

>Class methods and attributes are for general behaviors that all instances should have.
>Instance methods and attributes are for specific info for instances each.
>Consider the common property that `__init__` should have as a function: It is called with every creation of an *instance*.


Okay, excellent choice! Classes and object-oriented programming (OOP) are fundamental concepts in modern software development, including the kind of work you encounter in courses like CS61B. They allow us to structure our code in a way that mirrors real-world concepts, making complex systems more manageable and maintainable.

Don't worry about the jargon yet. We'll approach this like building with LEGOs – starting with simple blocks and gradually assembling more intricate structures. We'll focus on the *why* and *how*, making sure the logic is clear every step of the way.

---

### 1. 引入与动机 (Hook & Motivation)

Imagine you're building a system to manage a university. You need to keep track of students. Each student has a name, an ID, and maybe a list of courses they're taking. They also need to be able to perform actions, like enrolling in a course or displaying their information.

You *could* manage this using separate variables and functions:

```python
# Student 1
student1_name = "Alice"
student1_id = "12345"
student1_courses = ["CS61A", "Math 53"]

# Student 2
student2_name = "Bob"
student2_id = "67890"
student2_courses = ["CS61B", "Physics 7A"]

def display_student_info(name, id, courses):
  print(f"Name: {name}, ID: {id}, Courses: {', '.join(courses)}")

display_student_info(student1_name, student1_id, student1_courses)
# Output: Name: Alice, ID: 12345, Courses: CS61A,Math 53
```

This quickly becomes cumbersome and error-prone. What if you want to add a GPA? You have to modify data structures and functions everywhere. The data (name, ID, courses) and the behavior (display info, enroll) related to a single student are scattered.

**This is where classes come in!** A class acts like a **blueprint** or a **template** for creating objects (in this case, student objects). It allows us to bundle the **data (attributes)** and the **behavior (methods)** that characterize a particular concept (like a "Student") into a single, neat package.

**Why do we need classes and inheritance?**

1.  **Organization & Encapsulation:** Group related data and functions together, making code cleaner, easier to understand, and modify. (The blueprint bundles all features of a standard house).
2.  **Reusability (Inheritance):** Create specialized blueprints based on existing ones, avoiding code duplication. (e.g., A "GradStudent" blueprint can inherit all features of a "Student" blueprint and add specifics like a thesis advisor).
3.  **Modeling the Real World:** Structure code in a way that naturally reflects the entities and relationships in the problem domain.

---

### 2. 必要知识回顾 (Prerequisite Review)

*   **Functions:** You know how to define (`def`) and call functions, passing arguments and returning values. Methods in classes are very similar to functions.
*   **Variables & Assignment:** How variables store references to data.
*   **Basic Data Types:** Lists, dictionaries, strings – we'll use these inside our classes.
*   **The Idea of Objects:** You've already used objects! Strings (`"hello"`), lists (`[1, 2]`), etc., are objects in Python. They have data (their content) and methods (`"hello".upper()`, `my_list.append(3)`). Classes allow us to define our *own* types of objects.

---

### 3. 直观解释与感性认识 (Intuitive Explanation)

Let's stick with the blueprint analogy:

*   **Class:** The **blueprint** for a "Student". It defines *what* information a student has (name, ID - attributes) and *what* they can do (enroll, display info - methods).
*   **Object (Instance):** An actual **student** created *from* the blueprint. Alice is one instance, Bob is another. Each instance holds its *own* specific data (Alice's name, Bob's name) but shares the same structure and capabilities defined by the class.
*   **Attribute:** A piece of **data** associated with an object (a specific student). Like a field on a form: `name`, `id`.
*   **Method:** A **function** associated with an object, defining something it can *do*. Like an action button: `display_info()`, `enroll()`.
*   **`self`:** When defining methods inside the blueprint, `self` is a placeholder word that refers to the **actual student object (the instance)** that the method is being called on. When Alice calls `display_info()`, `self` inside the method refers to Alice. When Bob calls it, `self` refers to Bob. <span style="background:#b1ffff">It's how the method knows *which* student's data to use.</span>
*   **Inheritance:** Imagine you have a detailed blueprint for a "Building". Now you want to design a "House". A house is a *type of* building. Instead of starting from scratch, you can **inherit** the "Building" blueprint (getting foundations, walls, roof definitions) and then **add** house-specific things (bedrooms, kitchen) or **modify** existing parts (change the roof style).
    *   **Parent Class (Superclass):** The original blueprint ("Building").
    *   **Child Class (Subclass):** The new, specialized blueprint ("House") that inherits from the parent.
*   **`super()`:** When you're working on the "House" blueprint and need to refer back to something specific from the original "Building" blueprint (like calling the building's standard construction procedure before adding house specifics), `super()` is <span style="background:#b1ffff">the special tool to reliably access the parent blueprint's features.</span>

---

### 4. 逐步形式化与精确定义 (Gradual Formalization)

Let's translate these ideas into Python code.

**Defining a Simple Class:**

```python
class Student:
    # This is the blueprint for a Student

    # The __init__ method (constructor): Called automatically when a new Student object is created.
    # 'self' refers to the new object being created.
    # 'name' and 'student_id' are parameters passed during creation.
    def __init__(self, name, student_id):
        # Attributes: Data specific to each instance (each student)
        # We store the passed-in name and student_id onto the 'self' object.
        self.name = name  # Instance attribute
        self.student_id = student_id # Instance attribute
        self.courses = [] # Instance attribute, starts empty for each new student

    # An instance method: A function associated with the class, operating on an instance.
    # It always takes 'self' as the first parameter.
    def enroll(self, course_name):
        self.courses.append(course_name)
        print(f"{self.name} enrolled in {course_name}")

    def display_info(self):
        print(f"--- Student Info ---")
        print(f"Name: {self.name}")
        print(f"ID: {self.student_id}")
        print(f"Courses: {', '.join(self.courses) if self.courses else 'None'}")

# Creating Instances (Objects) from the Class (Blueprint)
student1 = Student("Alice", "12345") # Calls __init__ with name="Alice", student_id="12345"
student2 = Student("Bob", "67890")   # Creates a separate Student object

# Accessing Attributes and Calling Methods
print(student1.name)  # Output: Alice
student2.enroll("CS61B") # Output: Bob enrolled in CS61B
student1.enroll("CS61A") # Output: Alice enrolled in CS61A

student1.display_info()
# Output:
# --- Student Info ---
# Name: Alice
# ID: 12345
# Courses: CS61A

student2.display_info()
# Output:
# --- Student Info ---
# Name: Bob
# ID: 67890
# Courses: CS61B
```

**Key Components:**

*   **`class ClassName:`:** Keyword to start class definition.
*   **`__init__(self, ...)`:** The **initializer** (often called constructor). It *initializes* the state of a *newly created* instance. `self` is the instance itself. Other parameters are values needed to set up the object.
*   **`self`:** The conventional name for the **first parameter of instance methods**. It represents the instance on which the method was called. You use `self.attribute_name` to access or create instance attributes.
*   **Instance Attributes:** Variables belonging to a specific instance (object), created using `self.attribute = value`, typically within `__init__`. Each instance has its own copy (e.g., `student1.name` and `student2.name` can be different).
*   **Instance Methods:** Functions defined inside a class that operate on instances. They always receive `self` as the first argument, allowing them to access and modify the instance's attributes.

---

### 5. 核心原理与推导过程 (Core Principles & Inheritance Walkthrough)

Now, let's dive into **Inheritance**, **`super()`**, and the difference between **Class** and **Instance** members.

#### A. Inheritance: Extending the Blueprint

Imagine we want a `GradStudent` class. A `GradStudent` *is a* `Student`, but also has a `thesis_advisor`. Instead of copying all the `Student` code, we inherit:

```python
# Parent Class (already defined above)
# class Student: ...

# Child Class inheriting from Student
class GradStudent(Student): # Put the Parent class in parentheses

    # We need to initialize GradStudent. What about the Student parts (name, ID)?
    def __init__(self, name, student_id, advisor):
        # --- How to initialize the inherited 'Student' part? ---
        # Option 1 (Less flexible, Avoid): Directly call parent's __init__ using class name
        # Student.__init__(self, name, student_id) # Requires hardcoding 'Student'

        # Option 2 (Preferred): Use super()
        ** super() gives you a proxy object to delegate method calls to the parent class.
        
        super().__init__(name, student_id) # Calls the __init__ of the parent (Student)
                                           # Automatically passes 'self'

        # Now, add the attribute specific to GradStudent
        self.thesis_advisor = advisor 
        
        ** Instance attribute specific to GradStudent

    # We can add new methods specific to GradStudent
    def display_advisor(self):
        print(f"Advisor: {self.thesis_advisor}")

    # We can also Override methods from the Parent class
    # Let's make display_info include the advisor
    def display_info(self):
        # Option 1: Re-implement everything (Bad - duplicates code)
        # print(f"--- Grad Student Info ---")
        # print(f"Name: {self.name}") # Accesses inherited attribute
        # print(f"ID: {self.student_id}") # Accesses inherited attribute
        # print(f"Courses: {', '.join(self.courses) if self.courses else 'None'}") # Accesses inherited attribute

        # Option 2 (Better): Call the parent's version first using super(), then add specifics
        print("--- Grad Student Info ---") # Customize the header
        super().display_info() # Calls Student.display_info() for this instance
                               # This prints the Name, ID, Courses part

        # Now add the GradStudent specific part
        self.display_advisor() # Call our other method to print the advisor
```

**What does the Parent (`Student`) pass to the Child (`GradStudent`)?**

*   **Methods:** All methods defined in `Student` (like `enroll`, the original `display_info`) become available to `GradStudent` instances <span style="background:#b1ffff">*unless* overridden</span>.
*   **Attributes defined in Parent's `__init__`:** The *logic* in the parent's `__init__` defines *which* attributes a basic `Student` should have (`name`, `student_id`, `courses`). The child's `__init__` **must ensure** these are initialized, typically by calling the parent's `__init__` via `super()`.

**Why `super().__init__(...)` is crucial:**

1.  **Code Reuse:** You don't rewrite the initialization logic for `name`, `student_id`, `courses`. You delegate it to the parent blueprint which already knows how to do it.
2.  **Maintainability:** If `Student.__init__` changes later (e.g., adds a `major` attribute), you only need to update `Student.__init__` and potentially the `super().__init__()` call in `GradStudent` (if `major` needs to be passed up), not copy-paste the entire logic.
3.  **Handles Complex Inheritance:** `super()` is designed to work correctly even with multiple inheritance (inheriting from more than one parent), following Python's Method Resolution Order (MRO). Directly calling `Parent.__init__` can break in these more complex scenarios.

**Method Overriding and Extending:**

*   **Overriding:** When the child class defines a method with the **same name** as a method in the parent class (e.g., `display_info`), the child's version takes precedence for child instances. This allows specialization.
*   **Extending (using `super()` inside the method):** Often, you don't want to completely *replace* the parent's behavior but rather *add* to it. You override the method, but inside the child's method, you use `super().method_name()` to execute the parent's version first, and then add the child-specific logic. This is what we did in `GradStudent.display_info()`.

#### B. Class Attributes vs. Instance Attributes

So far, `name`, `student_id`, `courses`, `thesis_advisor` are **instance attributes**. Each *instance* (each student object) gets its own copy.

What <span style="background:#b1ffff">if we want a piece of data shared by *all* students, like the name of the university?</span>

```python
class Student:
    # Class Attribute: Defined inside the class, but outside any method (like __init__)
    # Shared by ALL instances of the class.
    university_name = "University of Python"

    def __init__(self, name, student_id):
        self.name = name          # Instance attribute
        self.student_id = student_id # Instance attribute
        self.courses = []         # Instance attribute

    # ... (other methods like enroll, display_info) ...

    def display_info(self):
        print(f"--- Student Info ({Student.university_name}) ---") # Access class attribute via ClassName
        # You can also access class attributes via self, but it's clearer via ClassName
        # print(f"--- Student Info ({self.university_name}) ---") # This also works (usually)
        print(f"Name: {self.name}")
        print(f"ID: {self.student_id}")
        print(f"Courses: {', '.join(self.courses) if self.courses else 'None'}")

# Creating instances
alice = Student("Alice", "12345")
bob = Student("Bob", "67890")

# Accessing class attribute
print(Student.university_name) # Access via class name -> University of Python
print(alice.university_name)  # Access via instance -> University of Python
print(bob.university_name)    # Access via instance -> University of Python

# Changing class attribute affects ALL instances
Student.university_name = "Python State University"
print(alice.university_name)  # -> Python State University
print(bob.university_name)    # -> Python State University

# IMPORTANT CAVEAT: Assigning to an instance creates an instance attribute
alice.university_name = "My Private Uni" # This creates an INSTANCE attribute 'university_name' on Alice
print(alice.university_name)   # -> My Private Uni (Alice's own attribute now hides the class one)
print(bob.university_name)     # -> Python State University (Bob still sees the class attribute)
print(Student.university_name) # -> Python State University (Class attribute itself is unchanged)
```

**Key Differences: Class vs. Instance Attributes**

| Feature          | Class Attribute                      | Instance Attribute                     |
| :--------------- | :----------------------------------- | :----------------------------------- |
| **Definition**   | Inside class, outside methods        | Inside `__init__` (usually), using `self.` |
| **Storage**      | Stored once with the class itself    | Stored with each individual object   |
| **Sharing**      | Shared by all instances              | Unique to each instance              |
| **Access**       | `ClassName.attr` or `self.attr`      | `self.attr` (within methods) or `instance.attr` (outside) |
| **Modification** | `ClassName.attr = value` (affects all) | `instance.attr = value` (affects only that instance) |
| **Use Cases**    | Constants, shared state, default values | Data specific to each object       |

#### C. Class Methods vs. Instance Methods

We've seen **instance methods** like `enroll` and `display_info`. They operate on a specific instance (`self`).

Sometimes, you need a method that relates to the *class itself*, not a specific instance. For example, maybe a method to create a `Student` object from a dictionary of data, or a method to get the total count of students created. These are **class methods**.

```python
class Student:
    university_name = "University of Python"
    num_students = 0 # Class attribute to track count

    def __init__(self, name, student_id):
        self.name = name
        self.student_id = student_id
        self.courses = []
        Student.num_students += 1 # Increment class attribute when a new student is made

    # Instance method (needs self)
    def display_info(self):
        print(f"Name: {self.name}, ID: {self.student_id}")

    # Class Method: Uses the @classmethod decorator
    # Takes 'cls' (the class itself) as the first argument, not 'self'
    @classmethod
    def get_num_students(cls):
        # Can access class attributes via 'cls'
        return f"Total students at {cls.university_name}: {cls.num_students}"

    @classmethod
    def from_dict(cls, data_dict):
        # Factory method: Creates an instance from structured data
        # 'cls' here refers to the Student class
        if 'name' in data_dict and 'id' in data_dict:
            # Calling cls(...) is like calling Student(...)
            return cls(data_dict['name'], data_dict['id'])
        else:
            # Handle error or return None perhaps
            return None # Or raise an error

# --- Usage ---
s1 = Student("Eve", "111")
s2 = Student("Frank", "222")

# Calling instance method
s1.display_info() # Output: Name: Eve, ID: 111

# Calling class method (can be called on the class or an instance)
print(Student.get_num_students()) # Output: Total students at University of Python: 2
print(s1.get_num_students())      # Output: Total students at University of Python: 2 (less common to call via instance)

# Using the factory class method
student_data = {"name": "Grace", "id": "333"}
s3 = Student.from_dict(student_data)
if s3:
    s3.display_info() # Output: Name: Grace, ID: 333
print(Student.get_num_students()) # Output: Total students at University of Python: 3
```

**Key Differences: Class vs. Instance Methods**

| Feature          | Class Method                         | Instance Method                       |
| :--------------- | :----------------------------------- | :------------------------------------ |
| **Decorator**    | `@classmethod`                       | None                                  |
| **First Argument**| `cls` (represents the class itself)  | `self` (represents the instance)      |
| **Purpose**      | Operates on the class; factory methods; accessing/modifying class state (`num_students`) | Operates on a specific instance; accessing/modifying instance state (`name`, `courses`) |
| **Calling**      | `ClassName.method()` or `instance.method()` (less common) | `instance.method()`                  |

*(There's also `@staticmethod`, which doesn't receive `cls` or `self`, essentially just a regular function namespaced within the class, but let's focus on instance and class methods for now).*

---

### 6. 示例与应用 (Examples & Application)

Let's put it all together with our `Student` and `GradStudent` example, incorporating class attributes/methods.

```python
class Student:
    """Represents a general student at a university.""" # Docstring! Good practice.
    university_name = "University of Python"
    num_students = 0

    def __init__(self, name, student_id):
        self.name = name
        self.student_id = student_id
        self.courses = []
        Student.num_students += 1
        print(f"Created Student: {self.name}")

    def enroll(self, course_name):
        self.courses.append(course_name)
        print(f"{self.name} enrolled in {course_name}")

    def display_info(self):
        print(f"--- Student Info ({self.university_name}) ---") # Access class attr via self
        print(f"Name: {self.name}")
        print(f"ID: {self.student_id}")
        print(f"Courses: {', '.join(self.courses) if self.courses else 'None'}")

    @classmethod
    def get_university_info(cls):
        return f"{cls.university_name} - Total Students: {cls.num_students}"


class GradStudent(Student):
    """Represents a graduate student, inheriting from Student."""
    num_grad_students = 0 # Class attribute specific to GradStudent

    def __init__(self, name, student_id, advisor):
        super().__init__(name, student_id) # Initialize the Student part
        self.thesis_advisor = advisor
        GradStudent.num_grad_students += 1
        print(f" -> Promoted to Grad Student with Advisor: {self.thesis_advisor}")

    # Override display_info to add advisor info
    def display_info(self):
        # Use super() to call the parent's display_info first
        super().display_info()
        print(f"Advisor: {self.thesis_advisor}")

    # New method specific to GradStudent
    def submit_thesis(self, title):
        print(f"{self.name} submitted thesis titled '{title}' advised by {self.thesis_advisor}")

    @classmethod
    def get_grad_student_count(cls):
        # Note: cls here refers to GradStudent
        return f"Total Grad Students: {cls.num_grad_students}"

# --- Let's use them! ---

# Create a regular student
alice = Student("Alice", "101")
alice.enroll("Math 101")

# Create a grad student
bob = GradStudent("Bob", "G001", "Dr. Turing")
bob.enroll("Advanced Algorithms")
bob.enroll("Machine Learning")

# Create another grad student
charlie = GradStudent("Charlie", "G002", "Dr. Hopper")

print("\n--- Displaying Info ---")
alice.display_info()
print("-" * 20)
bob.display_info()
print("-" * 20)
charlie.display_info()


print("\n--- University Stats ---")
# Access class methods
print(Student.get_university_info()) # Accessing parent's class method
print(GradStudent.get_university_info()) # Child can also access parent's class method!
print(GradStudent.get_grad_student_count()) # Accessing child's specific class method

# Note: Student doesn't know about grad student count
# print(Student.get_grad_student_count()) # This would cause an AttributeError

print("\n--- Grad Student Actions ---")
bob.submit_thesis("Theory of Computation")
```

**Observe the output carefully:** Notice how `__init__` calls print messages, how `super().__init__` ensures the base class initialization happens, how `super().display_info()` reuses code, and how class attributes (`num_students`, `num_grad_students`) track counts across instances.

---

### 7. 知识点总结与要点提炼 (Summary & Key Takeaways)

*   **Class:** A blueprint for creating objects. Bundles data (attributes) and behavior (methods). `class MyClass:`
*   **Instance (Object):** A specific realization created from a class blueprint. `my_obj = MyClass()`
*   **`__init__(self, ...)`:** The initializer method, called when an instance is created. Used to set up the initial state (instance attributes).
*   **`self`:** Reference to the instance itself, passed automatically as the first argument to instance methods.
*   **Instance Attributes:** Data unique to each instance, usually defined via `self.attr = value` in `__init__`.
*   **Instance Methods:** Functions associated with an instance, operate on `self`.
*   **Class Attributes:** Data shared by *all* instances of a class, defined inside the class but outside methods. Accessed via `ClassName.attr` or `self.attr`.
*   **Class Methods:** Functions associated with the class itself, defined with `@classmethod` and taking `cls` as the first argument. Operate on the class or class attributes. Useful for factory methods or class-level operations.
*   **Inheritance:** Creating a new class (child/subclass) based on an existing class (parent/superclass). `class Child(Parent):`
*   **What's Inherited:** Child gets parent's methods and class attributes. The parent's `__init__` structure dictates expected base attributes.
*   **`super()`:** A built-in function used in the child class to call methods from the parent class.
    *   `super().__init__(...)`: Crucial for calling the parent's initializer from the child's initializer to set up inherited attributes.
    *   `super().method_name(...)`: Used to call the parent's version of an overridden method, allowing you to *extend* rather than completely replace functionality.
*   **Method Overriding:** Child class provides its own implementation of a method that also exists in the parent.
*   **Method Extending:** Child class overrides a method but uses `super().method_name()` within its implementation to leverage the parent's logic.

---

### 8. 学科思想与延伸思考 (Underlying Philosophy & Further Thinking)

*   **Encapsulation:** Classes encapsulate data (attributes) and the code that operates on that data (methods) together. This hides internal complexity and protects data from unintended modification. Think of it like a TV: you use the remote (methods) without needing to know the complex circuitry inside (implementation details).
*   **Inheritance (Code Reuse & Specialization):** Inheritance is a powerful mechanism for reusing existing code and building hierarchies of related concepts (an "is-a" relationship: a `GradStudent` *is a* `Student`). It promotes the DRY (Don't Repeat Yourself) principle.
*   **Polymorphism (Briefly):** Notice how `alice.display_info()` and `bob.display_info()` were called the same way, but produced different outputs because `bob` (a `GradStudent`) used the overridden version. This ability of different objects to respond to the same method call in their own specific ways is called polymorphism ("many forms"). `super()` plays a key role in facilitating this while allowing code reuse.
*   **Composition vs. Inheritance:** Inheritance represents an "is-a" relationship. Sometimes, you have a "has-a" relationship (e.g., a `Car` *has an* `Engine`). In such cases, **composition** (where one object holds an instance of another object as an attribute) is often preferred over inheritance. Choosing between them is a key object-oriented design decision.
*   **Beyond the Basics:** Python's OOP includes many other features: "magic" methods (like `__str__` for string representation, `__eq__` for equality), properties (`@property`), abstract base classes (`abc` module), and multiple inheritance. We've built a solid foundation today!

**Thinking Question:**
Consider our `Student` and `GradStudent`. What if we also needed `UndergradStudent`? How would you structure the inheritance? What if both `GradStudent` and `UndergradStudent` needed a `major` attribute? Where would be the best place to define the `major` attribute and the logic to initialize it? (Hint: Think about commonality).

This might seem like a lot, but the core ideas – bundling data and behavior (classes), reusing and specializing blueprints (inheritance), and distinguishing between shared (class) and specific (instance) features – are incredibly powerful tools for organizing code. Practice creating your own simple classes and inheritance structures, and these concepts will become much clearer! Let me know if any part needs further clarification.