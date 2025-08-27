```
+-------------------------------------------------------------------------------------+
|                               OFF-CHAIN LAYER                                       |
|                (Data Collection, Processing, & Verification)                        |
+-------------------------------------------------------------------------------------+
|                                                                                     |
|  [Community App]                                                                    |
|        |                                                                            |
|        v                                                                            |
|  +-----------------------------+                                                    |
|  | dMRV Data Processing        |                                                    |
|  | Pipeline (Cloud AI/ML for   |                                                    |
|  | Carbon Quantification)      |                                                    |
|  +-----------------------------+                                                    |
|        |                                |                                           |
|        v                                v                                           |
|  +-----------------------------+    +-------------------------------+               |
|  | Data Storage                |    | Verification Portal           |               |
|  | - IPFS for Reports/Hashes   |<-->| - Review Data                 |               |
|  | - Cloud for Raw Data        |    | - Audit AI Model Output       |               |
|  +-----------------------------+    | - Digitally Sign & Approve    |               |
|                                     +-------------------------------+               |
|                                                                                     |
|                                (Verified Data Payload)                              |
+-------------------------------------------------------------------------------------+
                                      |                                              
                                      v                                              
+-------------------------------------------------------------------------------------+
|                                ORACLE BRIDGE                                        |
|                (Connecting Off-Chain Data to On-Chain Logic)                        |
+-------------------------------------------------------------------------------------+
|                                                                                     |
|  +----------------------------------------------+                                   |
|  | Decentralized Oracle Network (e.g. Chainlink)|                                   |
|  | - Fetches signed data from Verifier's API    |                                   |
|  | - Aggregates responses for integrity         |                                   |
|  | - Delivers data to Smart Contracts           |                                   |
|  +----------------------------------------------+                                   |
|                                      |                                              |
+-------------------------------------- v --------------------------------------------+
                                      |                                              
+-------------------------------------------------------------------------------------+
|                                ON-CHAIN LAYER                                       |
|                (Trust, Settlement, & Asset Management)                              |
|                     (e.g., Polygon, Avalanche)                                      |
+-------------------------------------------------------------------------------------+
|                                                                                     |
|  +---------------------------------------------+                                    |
|  | Smart Contract Suite                        |                                    |
|  | - Manages Projects & Vintages               |                                    |
|  | - Receives Oracle Data                      |                                    |
|  | - Triggers Issuance                         |                                    |
|  | - Stores Metadata                           |                                    |
|  | - Mints/Burns Tokens (ERC-1155)             |                                    |
|  +---------------------------------------------+                                    |
|         ^                  |                                                        |
|         | (Read/Write      v                                                        |
|         |  Transactions)   +------------------------------------------+             |
|         +----------------->| User Wallets & dApp Interfaces           |             |
|                            | (Developers, Credit Buyers, Exchanges,   |             |
|                            | Retirement Dashboards)                   |             |
|                            +------------------------------------------+             |
|                                                                                     |
+-------------------------------------------------------------------------------------+
```
