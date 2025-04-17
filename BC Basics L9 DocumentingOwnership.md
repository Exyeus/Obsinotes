Tsk: describing ownership in a way that is useful for a P2P system of *ledgers*.
How to document _onersp_ and handle transfers.
Ordering matters.
Transactions need integrity.

*Metaphor*.
Relay race. For a given team, to know the member carrying the baton, the member who was *handed over* at the latest *hand off*, is sufficient.
In order to keep track of who carried a baton at any given time, one needs
to record the time of each hand off and the athletes who were involved.

### Properties

The system must be transparent and comprehensive.
Anyone that read this ledger, should be able to correctly assert the owner of the goods.

Not only should the ownership be provided, the relevant evidence should also be provided.

Recording all ownerships is not actually applied in practical use. Instead, one maintains a list of all transfers of ownerships in a ledger in an *ongoing* fashion.
*Like the relay race*. Recording the comprehensive process of handing over, is sufficient for correctly judging the actual people holding the *baton*.

*def*. Invertory data: - 库存数据：指记录某个企业或组织所有库存物品的数量、种类、状态等信息的数据。网络 库存量资料 /有关库存的数据

*def*. Transaction data. Describing the transfers of ownership.

For Inventory data and transaction data, the first one just *state and claim*, while the second one *explain and justify*.

---
# Notes Highlights Only!

---
### How it works

Transfer needs:
- identifiers for both accounts
- amount to transfer
- time to be done
- fee paid for the sys 's work.'
- *A PROOF*

No centralized management, therefore the amount of the fee, is confirmed by asking the involved accounts in advance.

*A process*. The ledger is used the next time to clarify ownership by aggregating the transaction data it contains, the newly added transaction will be included in the aggregation and impact the *resulting state* of the ownership.

Without exaggeration, one can state that the history of
transaction data is the <span style="background:#d3f8b6">heart of any blockchain</span> that
manages ownership because it is the basis for
reconstructing the state of ownership.





























































