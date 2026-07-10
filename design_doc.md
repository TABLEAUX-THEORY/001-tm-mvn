# mvn-<id\>

<!--Can use html comments anywhere in the document. However, they should be considered "for document development" and not needed for reading of the final document. Will not appear on certain renderers.-->

## Title

\<The working title goes here.\>

## Description

\<A concise description of the project goes here.\>

### Visuals

#### <First Visual Group>

<TODO>

## Lore

### People

- **Actor:** Short description of **Actor**.

### Places

- **Place:** Short description of **Place**.

### Things

- **Thing:** Short description of **Thing**.

## Cited Data

<!--Data that is referenced in this design document. This is *not* a comprehensive list of data in the novel.-->

- **data_0:** Describe any important information about **data_0**.
- **data_1:** Describe any important information about **data_1**.

## Scripts

### <extension>

#### 0

- **<Entry>:** Description.

## Flow

### LOOP0ID

```mermaid
flowchart LR
  %%Vals
  EX((EXIT))
  med0id_0["med0id<br><small>scr"]
  med0id_1["med1id<br><small>scr, scr"]
  
  %%Flow
  med0id_0-->med0id_1-->EX
```

### LOOP1ID

#### **PARAMS:** med0id_0[1], med2id_1[2], med3i_1[2]

<!--NOTE: Overlays can also be drawn *under* the main medium... Technically these are "underlays", but they are functionally identical other than draw order.-->

```mermaid
flowchart LR
  %% Overlays
  o0["med_overlay<br><small>[0]"]
  
  %% Vals
  EX((EXIT))
  med2id_1["med2id<br><small>scr, [1]"]
  med3id_0["med3id<br><small>scr, [0]"]
  med3id_1["med3id<br><small>scr, [1]"]

  %% Flow

  med2id_1 -->|"First branch requirements (human language.)"| med3id_0
  med2id_1 -->|"Second branch requirements (human language.)"| med3id_1
  %%All go to the same exit... There may be exit branches out of the 
  %% loop but these are explained one level up the stack, as loops,
  %% as mediums, may have variable numbers of exit branches.
  med3id_0 -->EX
  med3id_1 -->EX
  
  %% Underlays
  %% Though it is likely rare that more than one thread has a flow, I added an example here to show that it is possible. They can even cause an exit. It is also worth noting that, just because the thread has a flow, it does not need to reach the exit point. Only a single thread is required to reach exit in order for a loop to be valid.
  o1["med_underlay_0<br><small>scr"]-->o2["med_underlay_1<br><small>scr"]-->EX
```

---

### DEMO

<!--The process loop for the demo version.-->

```mermaid
flowchart LR
  %%Overlays
  %%(Yes, main may use overlays aswell, though ths will likely be rare.)

  %%Vals
  RE((RESTART))
  LOOP0ID[["LOOP0ID"]]
  LOOP1ID_0[["LOOP1ID<br><small>med0id_0{scr}<br>med2id_1{scr, scr}<br>med3id_1{scr, scr}"]]

  %%Flow
  LOOP0ID -->LOOP1ID_0
  LOOP1ID_0-->RE
```



### MAIN

<!--The process loop for the main version.-->

```mermaid
flowchart LR
  %%Overlays
  %%(Yes, main may use overlays aswell, though ths will likely be rare.)

  %%Vals
  RE((RESTART))
  LOOP0ID[["LOOP0ID"]]
  LOOP1ID_0[["LOOP1ID<br><small>med0id_0{scr}<br>med2id_1{scr, scr}<br>med3id_1{scr, scr}"]]
  med2id_0["med2id<br><small>scr, scr"]
  med2id_1["med2id<br><small>scr, scr"]
  med3id_0["med3id<br><small>scr, scr"]

  %%Flow
  LOOP0ID -->LOOP1ID_0
  LOOP1ID_0-->|"First branch requirements (human language.)"|med2id_0
  LOOP1ID_0-->|"Second branch requirements (human language.)"|med2id_1
  LOOP1ID_0-->|"Third branch requirements (human language.)"|med3id_0
  med2id_0-->RE
  med2id_1-->RE
  med3id_0-->RE
```
