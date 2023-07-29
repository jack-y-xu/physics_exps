# Involved classes:


Detector:

```cpp
Detector {
    Detector(INIReader& reader, Event* event);
    G4ThreeVector samplePoint();
    G4VPhysicalVolume* Construct();
};
```

```cpp
Event {
    void ProcessHits(G4Step*, G4TouchableHistory*) = 0;
    G4VUserPrimaryGeneratorAction* getGenerator();
    G4VModularPhysicsList* getPhysics();
    void exportToAnalysisManager();
};
```

```cpp

```

```cpp
Instance {
    void init(path filepath, bool visual);
    void run();
    void saveResults(path filepath);
};
```