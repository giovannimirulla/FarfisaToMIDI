# Contributing to Farfisa to MIDI

Thank you for your interest in contributing! This project converts a Farfisa keyboard into a MIDI controller using an Arduino board. We welcome contributions to improve compatibility, documentation, and functionality.

## How to Contribute

### 1. Fork the Repository
Click the "Fork" button in the top right corner of the repository page. This will create a copy of the repo under your GitHub account.

### 2. Clone Your Fork
```bash
git clone https://github.com/your-username/FarfisaToMIDI.git
cd FarfisaToMIDI
```

### 3. Create a New Branch
Always create a new branch for your work:
```bash
git checkout -b feature/your-feature-name
```

### 4. Make Your Changes
Edit code, improve documentation, or add compatibility for new boards (e.g., Arduino Uno, Mega, etc.).

### 5. Test Thoroughly
Make sure your changes work as expected:
- Upload to your Arduino board.
- Verify MIDI messages are sent and received correctly.
- Optionally test with GarageBand or FL Studio.

### 6. Commit and Push
```bash
git add .
git commit -m "Add: brief description of your change"
git push origin feature/your-feature-name
```

### 7. Create a Pull Request
Open a pull request from your branch to the `main` branch of this repository. Clearly describe what you’ve changed and why.

---

## Coding Guidelines

- Keep your code clean and well-commented.
- Use descriptive names for variables and functions.
- Follow the existing style of the codebase.

---

## Need Ideas?

Here are some ways you can contribute:
- Test the code on more Arduino models (e.g., Uno, Mega, Leonardo).
- Improve documentation (README, code comments).
- Add new MIDI features (velocity, channel selection, etc.).
- Add a web-based interface or configuration tool.

---

## Code of Conduct

Please be respectful and constructive. We aim to create a welcoming community for all contributors.

---

Thanks again for helping improve this project!