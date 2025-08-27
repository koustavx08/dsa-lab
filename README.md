Architectural Diagram
Code snippet

+---------------------------------------------------------------------------------+

| OFF-CHAIN LAYER |
| (Data Collection, Processing, & Verification) |
+---------------------------------------------------------------------------------+

| |
| [Community App] |
| | | | | |
| | | | | |
| v                      v                      v                   v |
| +---------------------------------------------------------------------------+ |
| | dMRV Data Processing Pipeline | |
| | (Cloud Infrastructure: AI/ML Models for Carbon Quantification) | |
| +---------------------------------------------------------------------------+ |
| | |
| v |
| +----------------------+      +-------------------------------------------+ |
| | Data Storage | | Verification Portal (for Auditors) | |
| | (IPFS for Reports/ | <--> | - Review Data | |
| | Hashes, Cloud for | | - Audit AI Model Output | |
| | Raw Data) | | - Digitally Sign & Approve Verification | |
| +----------------------+      +-------------------------------------------+ |
| | |
+-----------------------------------------------------|-------------------------+

| (Verified Data Payload)
                                                      v
+---------------------------------------------------------------------------------+

| ORACLE BRIDGE |
| (Connecting Off-Chain Data to On-Chain Logic) |
+---------------------------------------------------------------------------------+

| |
| +---------------------------------------------------------------------------+ |
| | Decentralized Oracle Network (e.g., Chainlink) [5] | |
| | - Fetches signed data from Verifier's API endpoint | |
| | - Aggregates responses for data integrity | |
| | - Delivers data to Smart Contracts on-chain | |
| +---------------------------------------------------------------------------+ |
| | |
+---------------------------------------|-----------------------------------------+
                                        v
+---------------------------------------------------------------------------------+

| ON-CHAIN LAYER |
| (Trust, Settlement, & Asset Management) |
| (e.g., Polygon, Avalanche) |
+---------------------------------------------------------------------------------+

| |
| +---------------------------------------------------------------------------+ |
| | Smart Contract Suite | |
| | | |
| | <-----> <-----> | |
| | - Manages Projects      - Receives Oracle Data        - Mints/Burns Tokens | |
| | - Stores Metadata       - Triggers Issuance           - (ERC-1155) [6] | |
| | - Manages Vintages | |
| +---------------------------------------------------------------------------+ |
| ^ |
| | (Read/Write Transactions) |
| v |
| +---------------------------------------------------------------------------+ |
| | User Wallets & dApp Interfaces | |
| | (Project Developers, Credit Buyers, Exchanges, Retirement Dashboards) | |
| +---------------------------------------------------------------------------+ |
| |
+---------------------------------------------------------------------------------+
Component Deep Dive
