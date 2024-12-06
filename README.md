# **SandBox**  

## **Project Description**  

This pet project was developed from scratch using the SFML library for graphical rendering. The goal of the project is to create a simulator with basic physics that allows experimentation with particles.

### **Development Timeline**  

1. **Initial Engine Versions**  
   The project began with a simple grid consisting of squares that could be filled with different colors.  

2. **Adaptation for Algorithmic Work / Implementation of Sand Physics**  
   The engine was refactored for easier manipulation of grid elements. This laid the foundation for implementing physics algorithms.  

![video1 (1)](https://github.com/user-attachments/assets/39e881bb-1977-4188-becf-37b97b13aaea)


3. **improvement and optimization**  
   The engine was updated to support double buffering and multi-frame animation, enabling the simulation of sand-like particle physics.  A lot of work was done on optimization, which allowed to increase the scale of the grid and maintain a stable FPS (around 80 - 140 depending on the CPU)

![video2](https://github.com/user-attachments/assets/e86557e6-5bb7-4511-9e4e-8c6dfe6f4675)


  
4. **Current Status**  
   The project is in beta. Core functionality is implemented, and bugs related to engine have been fixed.  The functioning of sand physics has been brought to an ideal. As for the water, everything is not so good. For good water physics, the engine needs to be reworked a bit

![video3](https://github.com/user-attachments/assets/ac71e5bb-d297-419b-99f3-84f4a7540bd1)


![doc_2024-12-07_00-17-25](https://github.com/user-attachments/assets/94bc2f8b-22c0-4e0b-b617-ae14f35e04ee)


---

## **How to Use the Program**  

### **Installation**  

1. Download the archive from the **Release** folder.  
2. Unzip it.  
3. Run the **SandBox.exe** file.  

### **Main Features**  

- **Spawn particles**: Use the left mouse button.  
- **Select particle type**: Press the keys `1`, `2`, `3`, `4`.  

### **Particle Types**  

1. **Void Particle**  
   - Destroys other particles.  
   - Press `1` to select.  

2. **Static Particle**  
   - Static, immobile particle with no physical properties.  
   - Press `2` to select.  

3. **Sand Particle**  
   - Main particle. Implements sand physics.  
   - Press `3` to select.  

4. **Beta Water Particle**  
   - Experimental particle with water physics.  
   - **WARNING:** This feature is not optimized and may reduce FPS.  
   - Press `4` to select.  

---

## **Features**  

- **Graphics**: Implemented using SFML.  
- **Physics**: Simulates sand behavior.  
- **Double Buffering**: Ensures smooth animation.  

---

## **Future Plans**  

- Optimize water physics.  
- Add new particle types.  
- Improve performance.  
