# **SandBox**  

## **Project Description**  

This pet project was developed from scratch using the SFML library for graphical rendering. The goal of the project is to create a simulator with basic physics that allows experimentation with particles.

### **Development Timeline**  

1. **Initial Engine Versions**  
   The project began with a simple grid consisting of squares that could be filled with different colors.  

2. **Adaptation for Algorithmic Work / Implementation of Sand Physics**  
   The engine was refactored for easier manipulation of grid elements. This laid the foundation for implementing physics algorithms.  


![video1](https://github.com/user-attachments/assets/2c29d561-58f7-4466-919e-5f8309550d59)



3. **improvement and optimization**  
   The engine was updated to support double buffering and multi-frame animation, enabling the simulation of sand-like particle physics.  A lot of work was done on optimization, which allowed to increase the scale of the grid and maintain a stable FPS (around 80 - 140 depending on the CPU)



![video2](https://github.com/user-attachments/assets/2de3b7be-9607-4b6c-ba3a-5f175cf014ad)


  
4. **Current Status**  
   The project is in beta. Core functionality is implemented, and bugs related to engine have been fixed.  The functioning of sand physics has been brought to an ideal. As for the water, everything is not so good. For good water physics, the engine needs to be reworked a bit


![video3](https://github.com/user-attachments/assets/2bd542a6-b0c3-4ad8-b4a0-c57fd321e1cd)

![video4](https://github.com/user-attachments/assets/d5a51633-dea7-46e7-86a2-616b8fe5188d)


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
