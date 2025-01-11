# Fract-ol 🌌

![Fractal Example](pics/fractal2.jpeg)

**Fract-ol** is a visually stunning fractal generation program built in C. Utilizing the modern MLX42 graphics library, Fract-ol renders intricate fractals such as the Mandelbrot and Julia sets with real-time controls for zooming, panning, and iteration adjustments.

## Features ✨

- **Interactive Fractal Exploration:** Zoom, pan, and modify iterations dynamically.
- **Multiple Fractal Sets:**
  - Mandelbrot Set
  - Julia Set (customizable with complex parameters)
- **Smooth Color Transitions:** Gradient-based colorization for an immersive visual experience.
- **Keyboard & Mouse Controls:** Intuitive inputs for seamless interaction.
- **Customizable Parameters:** Adjust the view and iterations to explore fractal depths.

## Installation ⚙️

### Requirements

- **C Compiler**: GCC, Clang, or similar.
- **MLX42 Library**: Ensure you have MLX42 installed. Follow the [MLX42 documentation](https://github.com/codam-coding-college/MLX42) for setup.
- **Libft**: The custom `libft` library is a dependency.

### Build Instructions

1. Clone the repository:
   ```bash
   git clone git@github.com:NikolasGoulios/Fract-ol.git
   cd fract-ol

2. Compile the project using the provided Makefile:
	```bash
	make

3. Run the program:
	```
	./fractol [fractal_name] [optional parameters]

### Usage

Command-line Arguments
```bash
Usage: ./fractol [fractol_name] [complex_number]
```

```bash
./fractol mandelbrot
```

```bash
./fractol julia -0.5 0.4
```

## Core Components 🛠️

- **Fractal Calculation**: Implements fractal-specific formulas (Mandelbrot, Julia).
- **Rendering**: Converts fractal computations to pixel data.
- **Event Handling**: Supports keyboard and mouse interaction for real-time updates.
- **Utility Functions**: Manages cleanup, parsing, and initialization tasks.


![Math](pics/fractal3.jpeg)


### That Was it. Thank you all !!!